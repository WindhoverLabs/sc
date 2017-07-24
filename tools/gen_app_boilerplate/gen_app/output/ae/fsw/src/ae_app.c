/*==============================================================================
Copyright (c) 2015, Windhover Labs
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of CmdIn nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY AEPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, AEEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

ae_app.c
*/

#include "ae_app.h"
#include "ae_msgids.h"
#include "ae_perfids.h"
#include <string.h>

AE_AppData_t AE_AppData;

void AE_AppMain(void)
{
    int32 Status = CFE_SUCCESS;
   
    /* Register the application with Executive Services */
    CFE_ES_RegisterApp();

    /* Create the first Performance Log entry */
    CFE_ES_PerfLogEntry(AE_APPMAIN_PERF_ID); 
   
    /* Perform application specific initialization */
    Status = AE_AppInit();
   
    if (Status != CFE_SUCCESS)
    {
        AE_AppData.RunStatus = CFE_ES_APP_ERROR;
    }
   
   /* Application main loop */
    while(CFE_ES_RunLoop(&AE_AppData.RunStatus) == TRUE)
    {
        /* Performance Log exit stamp */
        CFE_ES_PerfLogExit(AE_APPMAIN_PERF_ID);
        
        /* Wait for the next Software Bus message */
        Status = CFE_SB_RcvMsg(&AE_AppData.MsgPtr, AE_AppData.CmdPipe, AE_SB_TIMEOUT);

        /* Performance Log Entry Stamp */
        CFE_ES_PerfLogEntry(AE_APPMAIN_PERF_ID);

        if (Status == CFE_SUCCESS)
        {
            /*
             * Process Software Bus message. If there are fatal errors
             * in command processing the command can alter the global
             * RunStatus variable to exit the main event loop.
             */
            AE_AppPipe(AE_AppData.MsgPtr);
        }
        else
        {
           /* 
            * This is an example of exiting on an error.
            * Note that a SB read error is not always going to
            * result in an app quitting.
            */
            CFE_EVS_SendEvent(AE_PIPE_ERR_EID, CFE_EVS_ERROR, \
                              "SB Pipe Read Error, AE App will exit. RC = 0x%08X", (unsigned int)Status);

            AE_AppData.RunStatus = CFE_ES_APP_ERROR;
        }

   } /* end CFS_ES_RunLoop while */
   
   /* Performance Log exit stamp */
   CFE_ES_PerfLogExit(AE_APPMAIN_PERF_ID);
   
   /* Exit the application */
   CFE_ES_ExitApp(AE_AppData.RunStatus);
} /* end AE_AppMain */


int32 AE_AppInit(void)
{
    int32  Status = CFE_SUCCESS;

    /* Setup the RunStatus variable */
    AE_AppData.RunStatus = CFE_ES_APP_RUN;

    /* Initialize app command execution counters */
    AE_AppData.CmdCounter = 0;
    AE_AppData.ErrCounter = 0;

    /* Initialize app configuration data */
    strcpy(AE_AppData.PipeName, AE_SB_PIPE_1_NAME);

    AE_AppData.PipeDepth = AE_PIPE_DEPTH;

    /* Register event filter table */
    Status = CFE_EVS_Register(NULL, 0, CFE_EVS_BINARY_FILTER);

    if (Status != CFE_SUCCESS)
    {
        CFE_ES_WriteToSysLog("AE App: Error Registering Events, RC = 0x%08X\n", (unsigned int)Status);
        return (Status);
    }
    /* Initialize housekeeping packet (clear user data area) */
    CFE_SB_InitMsg(&AE_AppData.HkPacket, AE_HK_TLM_MID, sizeof(AE_HkPacket_t), TRUE);

    /* Create Software Bus message pipe */
    Status = CFE_SB_CreatePipe(&AE_AppData.CmdPipe, AE_AppData.PipeDepth, AE_AppData.PipeName);
    
    if (Status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(AE_PIPE_ERR_EID, CFE_EVS_ERROR, \
                              "SB Pipe Creation Error, AE App will exit. RC = 0x%08X", (unsigned int)Status);
    return (Status);
    }
    
    /* Subscribe to Housekeeping request commands */
    Status = CFE_SB_Subscribe(AE_SEND_HK_MID, AE_AppData.CmdPipe);

    if (Status != CFE_SUCCESS)
    {
        CFE_EVS_SendEvent(AE_PIPE_ERR_EID, CFE_EVS_ERROR, \
                            "Error Subscribing to HK Request, AE App will exit. RC = 0x%08X", (unsigned int)Status);
        return (Status);
    }
    
    /* Subscribe to AE ground command packets */
    Status = CFE_SB_Subscribe(AE_CMD_MID, AE_AppData.CmdPipe);
    if (Status != CFE_SUCCESS)
    {
       CFE_EVS_SendEvent(AE_PIPE_ERR_EID, CFE_EVS_ERROR, \
                            "Error Subscribing to AE Command, AE App will exit. RC = 0x%08X", (unsigned int)Status);
       return (Status);
    }
    
    /* Application startup event message */
    CFE_EVS_SendEvent(AE_INIT_INF_EID, CFE_EVS_INFORMATION, "AE: Application Initialized");
                         
    return(CFE_SUCCESS);

}

void AE_AppPipe(CFE_SB_MsgPtr_t msg)
{
    CFE_SB_MsgId_t MessageID = 0;
    uint16 CommandCode = 0;

    MessageID = CFE_SB_GetMsgId(msg);
    switch (MessageID)
    {
        /* Housekeeping telemetry request */
        case AE_SEND_HK_MID:
            AE_HousekeepingCmd(msg);
            break;

        /* AE ground commands */
        case AE_CMD_MID:

            CommandCode = CFE_SB_GetCmdCode(msg);
            switch (CommandCode)
            {
                case AE_NOOP_CC:
                    AE_NoopCmd(msg);
                    break;

                case AE_RESET_CC:
                    AE_ResetCmd(msg);
                    break; 

                case AE_HELLOWORLD_CC: 
                    AE_HelloWorldCmd(msg); 
                    break;

                default:
                    CFE_EVS_SendEvent(AE_CC1_ERR_EID, CFE_EVS_ERROR, \
                    "Invalid ground command code: ID = 0x%X, CC = %d", \
                                    MessageID, CommandCode);
                    break;
            }
            break;

        default:
            AE_AppData.ErrCounter++;
            CFE_EVS_SendEvent(AE_MID_ERR_EID, CFE_EVS_ERROR,
                            "Invalid command pipe message ID: 0x%X",
                            MessageID);
            break;
    }

    return;

} /* End of AE_AppPipe() */


void AE_HousekeepingCmd(CFE_SB_MsgPtr_t msg)
{
    uint16 ExpectedLength = sizeof(AE_NoArgsCmd_t); 
    uint16 i;
    
    /* Verify command packet length */
    if (AE_VerifyCmdLength(msg, ExpectedLength))
    {
       /* Get command execution counters */
        AE_AppData.HkPacket.CmdCounter = AE_AppData.CmdCounter;
        AE_AppData.HkPacket.ErrCounter = AE_AppData.ErrCounter;
        
        CFE_EVS_SendEvent(AE_PROCCESS_INF_EID,CFE_EVS_INFORMATION, "AE: Hello Housekeeping!");
        
        /* Send housekeeping telemetry packet */
        CFE_SB_TimeStampMsg((CFE_SB_Msg_t *) &AE_AppData.HkPacket);
        CFE_SB_SendMsg((CFE_SB_Msg_t *) &AE_AppData.HkPacket);

        /* This command does not affect the command execution counter */
    }

    return;

} /* End of AE_HousekeepingCmd() */


void AE_NoopCmd(CFE_SB_MsgPtr_t msg)
{
    uint16 ExpectedLength = sizeof(AE_NoArgsCmd_t);

    /* Verify command packet length */
    if (AE_VerifyCmdLength(msg, ExpectedLength))
    {
        AE_AppData.CmdCounter++;

        CFE_EVS_SendEvent(AE_NOOP_INF_EID, CFE_EVS_INFORMATION, \
                         "No-op command");
    }

    return;

} /* End of AE_NoopCmd() */


void AE_ResetCmd(CFE_SB_MsgPtr_t msg)
{
    uint16 ExpectedLength = sizeof(AE_NoArgsCmd_t); 

    /* Verify command packet length */
    if (AE_VerifyCmdLength(msg, ExpectedLength))
    {
        AE_AppData.CmdCounter = 0;
        AE_AppData.ErrCounter = 0;

        CFE_EVS_SendEvent(AE_RESET_INF_EID, CFE_EVS_INFORMATION, \
                         "Reset Counters command received");
    }

    return;

} /* End of AE_ResetCmd() */


void AE_HelloWorldCmd(CFE_SB_MsgPtr_t msg)
{
    uint16 ExpectedLength = sizeof(AE_NoArgsCmd_t);

    /* Verify command packet length */
    if (AE_VerifyCmdLength(msg, ExpectedLength))
    {
        CFE_EVS_SendEvent(AE_PROCCESS_INF_EID,CFE_EVS_INFORMATION, "AE: Hello World!");
    }

    return;

} /* End of AE_HelloWorldCmd() */


boolean AE_VerifyCmdLength(CFE_SB_MsgPtr_t msg, uint16 ExpectedLength)
{
    boolean result = TRUE;
    uint16 ActualLength = CFE_SB_GetTotalMsgLength(msg);

    /* Verify the command packet length */
    if (ExpectedLength != ActualLength)
    {
        CFE_SB_MsgId_t MessageID = CFE_SB_GetMsgId(msg);
        uint16 CommandCode = CFE_SB_GetCmdCode(msg);

        CFE_EVS_SendEvent(AE_LEN_ERR_EID, CFE_EVS_ERROR, \
           "Invalid cmd pkt: ID = 0x%X,  CC = %d, Len = %d", \
                          MessageID, CommandCode, ActualLength);
        result = FALSE;
        AE_AppData.ErrCounter++;
    }

    return(result);

} /* End of AE_VerifyCmdLength() */





