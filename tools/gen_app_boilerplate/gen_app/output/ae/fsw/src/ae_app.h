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

ae_app.h
*/

#ifndef _ae_app_
#define _ae_app_

#include "cfe.h"

/* Event message ID's */
#define AE_INIT_INF_EID       1  /* start up message "informational" */
#define AE_NOOP_INF_EID       2  /* processed command "informational" */
#define AE_RESET_INF_EID      3
#define AE_PROCCESS_INF_EID   4
#define AE_MID_ERR_EID        5  /* invalid command packet "error" */
#define AE_CC1_ERR_EID        6
#define AE_LEN_ERR_EID        7
#define AE_PIPE_ERR_EID       8
#define AE_EVT_COUNT          8  /* count of event message ID's */

/* Example command packet command codes */
#define AE_NOOP_CC            0  /* no-op command */
#define AE_RESET_CC           1  /* reset counters */
#define AE_HELLOWORLD_CC      2  /* hello world command */

/* Example command pipe parameters */
#define AE_PIPE_DEPTH         12 /* Depth of the Command Pipe for Application */

/* Example app specific definitions */
#define AE_SB_TIMEOUT         CFE_SB_PEND_FOREVER  /* Can be a value in milliseconds */
#define AE_SB_PIPE_1_NAME     "AE_CMD_PIPE"

/* Type definition (generic "no arguments" command) */
typedef struct
{
    uint8                 CmdHeader[CFE_SB_CMD_HDR_SIZE];
} AE_NoArgsCmd_t;


/* Type definition (AE housekeeping) */
typedef struct
{
    uint8                 TlmHeader[CFE_SB_TLM_HDR_SIZE];

    /* Command interface counters */
    uint8                 CmdCounter;
    uint8                 ErrCounter;
} AE_HkPacket_t;


/** 
 *  \brief Example global data structure
 */
typedef struct
{
    /* Command interface counters */
    uint8                 CmdCounter;
    uint8                 ErrCounter;

    /* Housekeeping telemetry packet */
    AE_HkPacket_t         HkPacket;

    /* Operational data (not reported in housekeeping) */
    CFE_SB_MsgPtr_t       MsgPtr;
    CFE_SB_PipeId_t       CmdPipe;

    /* Run Status variable used in the main processing loop */
    uint32                RunStatus;

    /* Initialization data (not reported in housekeeping) */
    char                  PipeName[16];
    uint16                PipeDepth;
} AE_AppData_t;


/**
 * \brief Application entry point and main process loop
 */
void AE_AppMain(void);


/**
 * \brief Example app initialization
 */
int32 AE_AppInit(void);


/**
 * \brief Process command pipe message
 */
void AE_AppPipe(CFE_SB_MsgPtr_t msg);


/**
 * \brief On-board command (HK request)
 */
void AE_HousekeepingCmd(CFE_SB_MsgPtr_t msg);


/**
 * \brief ground command (NO-OP)
 */
void AE_NoopCmd(CFE_SB_MsgPtr_t msg);


/**
 * \brief ground command (reset counters)
 */
void AE_ResetCmd(CFE_SB_MsgPtr_t msg);


/**
 * \brief ground command (hello world command)
 */
void AE_HelloWorldCmd(CFE_SB_MsgPtr_t msg); 


/**
 * \brief Verify command packet length
 */
boolean AE_VerifyCmdLength(CFE_SB_MsgPtr_t msg, uint16 ExpectedLength); 


/* Exported Data */
extern AE_AppData_t     AE_AppData;

#endif /* _ae_app_ */

