/* This file was autogenerated from template version 0.0.0.2 and autogenerator version 0.0.0.1 */

#include "fc_serialization.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32 PX4_VehicleCommandMsg_t_Enc(const PX4_VehicleCommandMsg_t *inObject, char *inOutBuffer, uint32 inSize)
{
	bool status = false;
	pb_ostream_t stream;

	px4_vehicle_command_msg_pb pbMsg;

    pbMsg.Confirmation = inObject->Confirmation;
    pbMsg.Timestamp = inObject->Timestamp;
    pbMsg.TargetComponent = inObject->TargetComponent;
    pbMsg.Param7 = inObject->Param7;
    pbMsg.Param6 = inObject->Param6;
    pbMsg.Param5 = inObject->Param5;
    pbMsg.Param4 = inObject->Param4;
    pbMsg.Param3 = inObject->Param3;
    pbMsg.Param2 = inObject->Param2;
    pbMsg.Param1 = inObject->Param1;
    pbMsg.TargetSystem = inObject->TargetSystem;
    pbMsg.SourceSystem = inObject->SourceSystem;
    pbMsg.Command = inObject->Command;
    pbMsg.SourceComponent = inObject->SourceComponent;

	/* Create a stream that will write to our buffer. */
	stream = pb_ostream_from_buffer((pb_byte_t *)inOutBuffer, inSize);
	
	/* Now we are ready to encode the message. */
	status = pb_encode(&stream, px4_vehicle_command_msg_pb_fields, &pbMsg);

	/* Check for errors... */
	if (!status)
	{
        OS_printf("Error encoding msg: %s", PB_GET_ERROR(&stream));
		return 0;
	}

	return stream.bytes_written;
}

uint32 PX4_VehicleCommandMsg_t_Dec(const char *inBuffer, uint32 inSize, PX4_VehicleCommandMsg_t *inOutObject)
{
	bool status = false;
	pb_istream_t stream;

	px4_vehicle_command_msg_pb pbMsg;

    /* Create a stream that reads from the buffer. */
	stream = pb_istream_from_buffer((const pb_byte_t *)inBuffer, inSize);

	/* Now we are ready to decode the message. */
	status = pb_decode(&stream, px4_vehicle_command_msg_pb_fields, &pbMsg); 

	/* Check for errors... */
	if (!status)
	{
        OS_printf("Error decoding msg: %s", PB_GET_ERROR(&stream));
		return 0;
	}

    inOutObject->Confirmation = pbMsg.Confirmation;
    inOutObject->Timestamp = pbMsg.Timestamp;
    inOutObject->TargetComponent = pbMsg.TargetComponent;
    inOutObject->Param7 = pbMsg.Param7;
    inOutObject->Param6 = pbMsg.Param6;
    inOutObject->Param5 = pbMsg.Param5;
    inOutObject->Param4 = pbMsg.Param4;
    inOutObject->Param3 = pbMsg.Param3;
    inOutObject->Param2 = pbMsg.Param2;
    inOutObject->Param1 = pbMsg.Param1;
    inOutObject->TargetSystem = pbMsg.TargetSystem;
    inOutObject->SourceSystem = pbMsg.SourceSystem;
    inOutObject->Command = pbMsg.Command;
    inOutObject->SourceComponent = pbMsg.SourceComponent;

	return sizeof(PX4_VehicleCommandMsg_t);
}


uint32 PX4_PositionSetpointTripletMsg_t_Enc(const PX4_PositionSetpointTripletMsg_t *inObject, char *inOutBuffer, uint32 inSize)
{
	bool status = false;
	pb_ostream_t stream;

	px4_position_setpoint_triplet_pb pbMsg;

    pbMsg.Timestamp = inObject->Timestamp;
    pbMsg.Current.AccelerationIsForce = inObject->Current.AccelerationIsForce;
    pbMsg.Current.DisableMcYawControl = inObject->Current.DisableMcYawControl;
    pbMsg.Current.Yaw = inObject->Current.Yaw;
    pbMsg.Current.Lon = inObject->Current.Lon;
    pbMsg.Current.PitchMin = inObject->Current.PitchMin;
    pbMsg.Current.VX = inObject->Current.VX;
    pbMsg.Current.Valid = inObject->Current.Valid;
    pbMsg.Current.YawValid = inObject->Current.YawValid;
    pbMsg.Current.X = inObject->Current.X;
    pbMsg.Current.PositionValid = inObject->Current.PositionValid;
    pbMsg.Current.Yawspeed = inObject->Current.Yawspeed;
    pbMsg.Current.VelocityValid = inObject->Current.VelocityValid;
    pbMsg.Current.Type = inObject->Current.Type;
    pbMsg.Current.Z = inObject->Current.Z;
    pbMsg.Current.CruisingThrottle = inObject->Current.CruisingThrottle;
    pbMsg.Current.Lat = inObject->Current.Lat;
    pbMsg.Current.YawspeedValid = inObject->Current.YawspeedValid;
    pbMsg.Current.CruisingSpeed = inObject->Current.CruisingSpeed;
    pbMsg.Current.LoiterDirection = inObject->Current.LoiterDirection;
    pbMsg.Current.A_Z = inObject->Current.A_Z;
    pbMsg.Current.A_Y = inObject->Current.A_Y;
    pbMsg.Current.A_X = inObject->Current.A_X;
    pbMsg.Current.Y = inObject->Current.Y;
    pbMsg.Current.VY = inObject->Current.VY;
    pbMsg.Current.VZ = inObject->Current.VZ;
    pbMsg.Current.AcceptanceRadius = inObject->Current.AcceptanceRadius;
    pbMsg.Current.AccelerationValid = inObject->Current.AccelerationValid;
    pbMsg.Current.LoiterRadius = inObject->Current.LoiterRadius;
    pbMsg.Current.Alt = inObject->Current.Alt;
    pbMsg.Next.AccelerationIsForce = inObject->Next.AccelerationIsForce;
    pbMsg.Next.DisableMcYawControl = inObject->Next.DisableMcYawControl;
    pbMsg.Next.Yaw = inObject->Next.Yaw;
    pbMsg.Next.Lon = inObject->Next.Lon;
    pbMsg.Next.PitchMin = inObject->Next.PitchMin;
    pbMsg.Next.VX = inObject->Next.VX;
    pbMsg.Next.Valid = inObject->Next.Valid;
    pbMsg.Next.YawValid = inObject->Next.YawValid;
    pbMsg.Next.X = inObject->Next.X;
    pbMsg.Next.PositionValid = inObject->Next.PositionValid;
    pbMsg.Next.Yawspeed = inObject->Next.Yawspeed;
    pbMsg.Next.VelocityValid = inObject->Next.VelocityValid;
    pbMsg.Next.Type = inObject->Next.Type;
    pbMsg.Next.Z = inObject->Next.Z;
    pbMsg.Next.CruisingThrottle = inObject->Next.CruisingThrottle;
    pbMsg.Next.Lat = inObject->Next.Lat;
    pbMsg.Next.YawspeedValid = inObject->Next.YawspeedValid;
    pbMsg.Next.CruisingSpeed = inObject->Next.CruisingSpeed;
    pbMsg.Next.LoiterDirection = inObject->Next.LoiterDirection;
    pbMsg.Next.A_Z = inObject->Next.A_Z;
    pbMsg.Next.A_Y = inObject->Next.A_Y;
    pbMsg.Next.A_X = inObject->Next.A_X;
    pbMsg.Next.Y = inObject->Next.Y;
    pbMsg.Next.VY = inObject->Next.VY;
    pbMsg.Next.VZ = inObject->Next.VZ;
    pbMsg.Next.AcceptanceRadius = inObject->Next.AcceptanceRadius;
    pbMsg.Next.AccelerationValid = inObject->Next.AccelerationValid;
    pbMsg.Next.LoiterRadius = inObject->Next.LoiterRadius;
    pbMsg.Next.Alt = inObject->Next.Alt;
    pbMsg.Previous.AccelerationIsForce = inObject->Previous.AccelerationIsForce;
    pbMsg.Previous.DisableMcYawControl = inObject->Previous.DisableMcYawControl;
    pbMsg.Previous.Yaw = inObject->Previous.Yaw;
    pbMsg.Previous.Lon = inObject->Previous.Lon;
    pbMsg.Previous.PitchMin = inObject->Previous.PitchMin;
    pbMsg.Previous.VX = inObject->Previous.VX;
    pbMsg.Previous.Valid = inObject->Previous.Valid;
    pbMsg.Previous.YawValid = inObject->Previous.YawValid;
    pbMsg.Previous.X = inObject->Previous.X;
    pbMsg.Previous.PositionValid = inObject->Previous.PositionValid;
    pbMsg.Previous.Yawspeed = inObject->Previous.Yawspeed;
    pbMsg.Previous.VelocityValid = inObject->Previous.VelocityValid;
    pbMsg.Previous.Type = inObject->Previous.Type;
    pbMsg.Previous.Z = inObject->Previous.Z;
    pbMsg.Previous.CruisingThrottle = inObject->Previous.CruisingThrottle;
    pbMsg.Previous.Lat = inObject->Previous.Lat;
    pbMsg.Previous.YawspeedValid = inObject->Previous.YawspeedValid;
    pbMsg.Previous.CruisingSpeed = inObject->Previous.CruisingSpeed;
    pbMsg.Previous.LoiterDirection = inObject->Previous.LoiterDirection;
    pbMsg.Previous.A_Z = inObject->Previous.A_Z;
    pbMsg.Previous.A_Y = inObject->Previous.A_Y;
    pbMsg.Previous.A_X = inObject->Previous.A_X;
    pbMsg.Previous.Y = inObject->Previous.Y;
    pbMsg.Previous.VY = inObject->Previous.VY;
    pbMsg.Previous.VZ = inObject->Previous.VZ;
    pbMsg.Previous.AcceptanceRadius = inObject->Previous.AcceptanceRadius;
    pbMsg.Previous.AccelerationValid = inObject->Previous.AccelerationValid;
    pbMsg.Previous.LoiterRadius = inObject->Previous.LoiterRadius;
    pbMsg.Previous.Alt = inObject->Previous.Alt;

	/* Create a stream that will write to our buffer. */
	stream = pb_ostream_from_buffer((pb_byte_t *)inOutBuffer, inSize);
	
	/* Now we are ready to encode the message. */
	status = pb_encode(&stream, px4_position_setpoint_triplet_pb_fields, &pbMsg);

	/* Check for errors... */
	if (!status)
	{
        OS_printf("Error encoding msg: %s", PB_GET_ERROR(&stream));
		return 0;
	}

	return stream.bytes_written;
}

uint32 PX4_PositionSetpointTripletMsg_t_Dec(const char *inBuffer, uint32 inSize, PX4_PositionSetpointTripletMsg_t *inOutObject)
{
	bool status = false;
	pb_istream_t stream;

	px4_position_setpoint_triplet_pb pbMsg;

    /* Create a stream that reads from the buffer. */
	stream = pb_istream_from_buffer((const pb_byte_t *)inBuffer, inSize);

	/* Now we are ready to decode the message. */
	status = pb_decode(&stream, px4_position_setpoint_triplet_pb_fields, &pbMsg); 

	/* Check for errors... */
	if (!status)
	{
        OS_printf("Error decoding msg: %s", PB_GET_ERROR(&stream));
		return 0;
	}

    inOutObject->Timestamp = pbMsg.Timestamp;
    inOutObject->Current.AccelerationIsForce = pbMsg.Current.AccelerationIsForce;
    inOutObject->Current.DisableMcYawControl = pbMsg.Current.DisableMcYawControl;
    inOutObject->Current.Yaw = pbMsg.Current.Yaw;
    inOutObject->Current.Lon = pbMsg.Current.Lon;
    inOutObject->Current.PitchMin = pbMsg.Current.PitchMin;
    inOutObject->Current.VX = pbMsg.Current.VX;
    inOutObject->Current.Valid = pbMsg.Current.Valid;
    inOutObject->Current.YawValid = pbMsg.Current.YawValid;
    inOutObject->Current.X = pbMsg.Current.X;
    inOutObject->Current.PositionValid = pbMsg.Current.PositionValid;
    inOutObject->Current.Yawspeed = pbMsg.Current.Yawspeed;
    inOutObject->Current.VelocityValid = pbMsg.Current.VelocityValid;
    inOutObject->Current.Type = pbMsg.Current.Type;
    inOutObject->Current.Z = pbMsg.Current.Z;
    inOutObject->Current.CruisingThrottle = pbMsg.Current.CruisingThrottle;
    inOutObject->Current.Lat = pbMsg.Current.Lat;
    inOutObject->Current.YawspeedValid = pbMsg.Current.YawspeedValid;
    inOutObject->Current.CruisingSpeed = pbMsg.Current.CruisingSpeed;
    inOutObject->Current.LoiterDirection = pbMsg.Current.LoiterDirection;
    inOutObject->Current.A_Z = pbMsg.Current.A_Z;
    inOutObject->Current.A_Y = pbMsg.Current.A_Y;
    inOutObject->Current.A_X = pbMsg.Current.A_X;
    inOutObject->Current.Y = pbMsg.Current.Y;
    inOutObject->Current.VY = pbMsg.Current.VY;
    inOutObject->Current.VZ = pbMsg.Current.VZ;
    inOutObject->Current.AcceptanceRadius = pbMsg.Current.AcceptanceRadius;
    inOutObject->Current.AccelerationValid = pbMsg.Current.AccelerationValid;
    inOutObject->Current.LoiterRadius = pbMsg.Current.LoiterRadius;
    inOutObject->Current.Alt = pbMsg.Current.Alt;
    inOutObject->Next.AccelerationIsForce = pbMsg.Next.AccelerationIsForce;
    inOutObject->Next.DisableMcYawControl = pbMsg.Next.DisableMcYawControl;
    inOutObject->Next.Yaw = pbMsg.Next.Yaw;
    inOutObject->Next.Lon = pbMsg.Next.Lon;
    inOutObject->Next.PitchMin = pbMsg.Next.PitchMin;
    inOutObject->Next.VX = pbMsg.Next.VX;
    inOutObject->Next.Valid = pbMsg.Next.Valid;
    inOutObject->Next.YawValid = pbMsg.Next.YawValid;
    inOutObject->Next.X = pbMsg.Next.X;
    inOutObject->Next.PositionValid = pbMsg.Next.PositionValid;
    inOutObject->Next.Yawspeed = pbMsg.Next.Yawspeed;
    inOutObject->Next.VelocityValid = pbMsg.Next.VelocityValid;
    inOutObject->Next.Type = pbMsg.Next.Type;
    inOutObject->Next.Z = pbMsg.Next.Z;
    inOutObject->Next.CruisingThrottle = pbMsg.Next.CruisingThrottle;
    inOutObject->Next.Lat = pbMsg.Next.Lat;
    inOutObject->Next.YawspeedValid = pbMsg.Next.YawspeedValid;
    inOutObject->Next.CruisingSpeed = pbMsg.Next.CruisingSpeed;
    inOutObject->Next.LoiterDirection = pbMsg.Next.LoiterDirection;
    inOutObject->Next.A_Z = pbMsg.Next.A_Z;
    inOutObject->Next.A_Y = pbMsg.Next.A_Y;
    inOutObject->Next.A_X = pbMsg.Next.A_X;
    inOutObject->Next.Y = pbMsg.Next.Y;
    inOutObject->Next.VY = pbMsg.Next.VY;
    inOutObject->Next.VZ = pbMsg.Next.VZ;
    inOutObject->Next.AcceptanceRadius = pbMsg.Next.AcceptanceRadius;
    inOutObject->Next.AccelerationValid = pbMsg.Next.AccelerationValid;
    inOutObject->Next.LoiterRadius = pbMsg.Next.LoiterRadius;
    inOutObject->Next.Alt = pbMsg.Next.Alt;
    inOutObject->Previous.AccelerationIsForce = pbMsg.Previous.AccelerationIsForce;
    inOutObject->Previous.DisableMcYawControl = pbMsg.Previous.DisableMcYawControl;
    inOutObject->Previous.Yaw = pbMsg.Previous.Yaw;
    inOutObject->Previous.Lon = pbMsg.Previous.Lon;
    inOutObject->Previous.PitchMin = pbMsg.Previous.PitchMin;
    inOutObject->Previous.VX = pbMsg.Previous.VX;
    inOutObject->Previous.Valid = pbMsg.Previous.Valid;
    inOutObject->Previous.YawValid = pbMsg.Previous.YawValid;
    inOutObject->Previous.X = pbMsg.Previous.X;
    inOutObject->Previous.PositionValid = pbMsg.Previous.PositionValid;
    inOutObject->Previous.Yawspeed = pbMsg.Previous.Yawspeed;
    inOutObject->Previous.VelocityValid = pbMsg.Previous.VelocityValid;
    inOutObject->Previous.Type = pbMsg.Previous.Type;
    inOutObject->Previous.Z = pbMsg.Previous.Z;
    inOutObject->Previous.CruisingThrottle = pbMsg.Previous.CruisingThrottle;
    inOutObject->Previous.Lat = pbMsg.Previous.Lat;
    inOutObject->Previous.YawspeedValid = pbMsg.Previous.YawspeedValid;
    inOutObject->Previous.CruisingSpeed = pbMsg.Previous.CruisingSpeed;
    inOutObject->Previous.LoiterDirection = pbMsg.Previous.LoiterDirection;
    inOutObject->Previous.A_Z = pbMsg.Previous.A_Z;
    inOutObject->Previous.A_Y = pbMsg.Previous.A_Y;
    inOutObject->Previous.A_X = pbMsg.Previous.A_X;
    inOutObject->Previous.Y = pbMsg.Previous.Y;
    inOutObject->Previous.VY = pbMsg.Previous.VY;
    inOutObject->Previous.VZ = pbMsg.Previous.VZ;
    inOutObject->Previous.AcceptanceRadius = pbMsg.Previous.AcceptanceRadius;
    inOutObject->Previous.AccelerationValid = pbMsg.Previous.AccelerationValid;
    inOutObject->Previous.LoiterRadius = pbMsg.Previous.LoiterRadius;
    inOutObject->Previous.Alt = pbMsg.Previous.Alt;

	return sizeof(PX4_PositionSetpointTripletMsg_t);
}


uint32 PX4_ManualControlSetpointMsg_t_Enc(const PX4_ManualControlSetpointMsg_t *inObject, char *inOutBuffer, uint32 inSize)
{
	bool status = false;
	pb_ostream_t stream;

	px4_manual_control_setpoint_pb pbMsg;

    pbMsg.timestamp = inObject->Timestamp;
	pbMsg.x = inObject->X;
	pbMsg.y = inObject->Y;
	pbMsg.z = inObject->Z;
	pbMsg.r = inObject->R;
	pbMsg.flaps = inObject->Flaps;
	pbMsg.aux1 = inObject->Aux1;
	pbMsg.aux2 = inObject->Aux2;
	pbMsg.aux3 = inObject->Aux3;
	pbMsg.aux4 = inObject->Aux4;
	pbMsg.aux5 = inObject->Aux5;
	pbMsg.mode_switch = inObject->ModeSwitch;
	pbMsg.return_switch = inObject->ReturnSwitch;
	pbMsg.rattitude_switch = inObject->RattitudeSwitch;
	pbMsg.posctl_switch = inObject->PosctlSwitch;
	pbMsg.loiter_switch = inObject->LoiterSwitch;
	pbMsg.acro_switch = inObject->AcroSwitch;
	pbMsg.offboard_switch = inObject->OffboardSwitch;
	pbMsg.kill_switch = inObject->KillSwitch;
    pbMsg.arm_switch = inObject->ArmSwitch;
	pbMsg.transition_switch = inObject->TransitionSwitch;
    pbMsg.gear_switch = inObject->GearSwitch;
	pbMsg.mode_slot = inObject->ModeSlot;
	pbMsg.data_source = inObject->DataSource;
    pbMsg.stab_switch = inObject->StabSwitch;
    pbMsg.man_switch = inObject->ManSwitch;

	/* Create a stream that will write to our buffer. */
	stream = pb_ostream_from_buffer((pb_byte_t *)inOutBuffer, inSize);
	
	/* Now we are ready to encode the message. */
	status = pb_encode(&stream, px4_manual_control_setpoint_pb_fields, &pbMsg);

	/* Check for errors... */
	if (!status)
	{
        OS_printf("Error encoding msg: %s", PB_GET_ERROR(&stream));
		return 0;
	}

	return stream.bytes_written;
}

uint32 PX4_ManualControlSetpointMsg_t_Dec(const char *inBuffer, uint32 inSize, PX4_ManualControlSetpointMsg_t *inOutObject)
{
	bool status = false;
	pb_istream_t stream;

	px4_manual_control_setpoint_pb pbMsg;

    /* Create a stream that reads from the buffer. */
	stream = pb_istream_from_buffer((const pb_byte_t *)inBuffer, inSize);

	/* Now we are ready to decode the message. */
	status = pb_decode(&stream, px4_manual_control_setpoint_pb_fields, &pbMsg); 

	/* Check for errors... */
	if (!status)
	{
        OS_printf("Error decoding msg: %s", PB_GET_ERROR(&stream));
		return 0;
	}

	inOutObject->Timestamp = pbMsg.timestamp;
	inOutObject->X = pbMsg.x;
	inOutObject->Y = pbMsg.y;
	inOutObject->Z = pbMsg.z;
	inOutObject->R = pbMsg.r;
	inOutObject->Flaps = pbMsg.flaps;
	inOutObject->Aux1 = pbMsg.aux1;
	inOutObject->Aux2 = pbMsg.aux2;
	inOutObject->Aux3 = pbMsg.aux3;
	inOutObject->Aux4 = pbMsg.aux4;
	inOutObject->Aux5 = pbMsg.aux5;
	inOutObject->ModeSwitch = pbMsg.mode_switch;
	inOutObject->ReturnSwitch = pbMsg.return_switch;
	inOutObject->RattitudeSwitch = pbMsg.rattitude_switch;
	inOutObject->PosctlSwitch = pbMsg.posctl_switch;
	inOutObject->LoiterSwitch = pbMsg.loiter_switch;
	inOutObject->AcroSwitch = pbMsg.acro_switch;
	inOutObject->OffboardSwitch = pbMsg.offboard_switch;
	inOutObject->KillSwitch = pbMsg.kill_switch;
    inOutObject->ArmSwitch = pbMsg.arm_switch;
	inOutObject->TransitionSwitch = pbMsg.transition_switch;
    inOutObject->GearSwitch = pbMsg.gear_switch;
	inOutObject->ModeSlot = pbMsg.mode_slot;
    inOutObject->DataSource = pbMsg.data_source;
    inOutObject->StabSwitch = pbMsg.stab_switch;
    inOutObject->ManSwitch = pbMsg.man_switch;

	return sizeof(PX4_ManualControlSetpointMsg_t);
}


#ifdef __cplusplus
} /* extern "C" */
#endif
