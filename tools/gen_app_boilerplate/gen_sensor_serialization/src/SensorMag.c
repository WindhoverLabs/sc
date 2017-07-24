uint32 AE_SensorMag_Enc(const PX4_SensorMagMsg_t *inObject, char *inOutBuffer, uint32 inSize)
{
	bool status = false;
	px4_sensor_mag_pb pbMsg;
	
	pbMsg.temperature = inObject->Temperature;
	pbMsg.scaling = inObject->Scaling;
	pbMsg.range_ga = inObject->Range;
	pbMsg.y_raw = inObject->YRaw;
	pbMsg.z_raw = inObject->ZRaw;
	pbMsg.error_count = inObject->ErrorCount;
	pbMsg.y = inObject->Y;
	pbMsg.x = inObject->X;
	pbMsg.z = inObject->Z;
	pbMsg.x_raw = inObject->XRaw;
	pbMsg.device_id = inObject->DeviceID;

	/* Create a stream that will write to our buffer. */
	pb_ostream_t stream = pb_ostream_from_buffer((pb_byte_t *)inOutBuffer, inSize);

	/* Now we are ready to encode the message. */
	status = pb_encode(&stream, px4_sensor_mag_pb_fields, &pbMsg); // TODO: Assumes [type]_fields is a standard
	/* Check for errors... */
	if (!status)
	{
		return 0;
	}

	return stream.bytes_written;
}

uint32 AE_SensorMag_Dec(const char *inBuffer, uint32 inSize, PX4_SensorMagMsg_t *inOutObject)
{
	bool status = false;
	px4_sensor_mag_pb pbMsg;

	/* Create a stream that reads from the buffer. */
	pb_istream_t stream = pb_istream_from_buffer((const pb_byte_t *)inBuffer, inSize);

	/* Now we are ready to decode the message. */
	status = pb_decode(&stream, px4_sensor_mag_pb_fields, &pbMsg); // TODO: Assumes [type]_fields is a standard

	/* Check for errors... */
	if (!status)
	{
		return 0;
	}
	
	inOutObject->Temperature = pbMsg.temperature;
	inOutObject->Scaling = pbMsg.scaling;
	inOutObject->Range = pbMsg.range_ga;
	inOutObject->YRaw = pbMsg.y_raw;
	inOutObject->ZRaw = pbMsg.z_raw;
	inOutObject->ErrorCount = pbMsg.error_count;
	inOutObject->Y = pbMsg.y;
	inOutObject->X = pbMsg.x;
	inOutObject->Z = pbMsg.z;
	inOutObject->XRaw = pbMsg.x_raw;
	inOutObject->DeviceID = pbMsg.device_id;

	return sizeof(PX4_SensorMagMsg_t);
}
