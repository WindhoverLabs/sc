{{cookiecutter.return_type}} {{cookiecutter.app_name}}_{{cookiecutter.func_name}}_Enc(const {{cookiecutter.msg_type}} *inObject, char *inOutBuffer, uint32 inSize)
{
	bool status = false;
	{{cookiecutter.pb_msg_type}} pbMsg;
	{% for pb_var, msg_var in cookiecutter.var_names.iteritems() %}
	pbMsg.{{pb_var}} = inObject->{{msg_var}};{% endfor %}

	/* Create a stream that will write to our buffer. */
	pb_ostream_t stream = pb_ostream_from_buffer((pb_byte_t *)inOutBuffer, inSize);

	/* Now we are ready to encode the message. */
	status = pb_encode(&stream, {{cookiecutter.pb_msg_type}}_fields, &pbMsg); // TODO: Assumes [type]_fields is a standard
	/* Check for errors... */
	if (!status)
	{
		return 0;
	}

	return stream.bytes_written;
}

{{cookiecutter.return_type}} {{cookiecutter.app_name}}_{{cookiecutter.func_name}}_Dec(const char *inBuffer, uint32 inSize, {{cookiecutter.msg_type}} *inOutObject)
{
	bool status = false;
	{{cookiecutter.pb_msg_type}} pbMsg;

	/* Create a stream that reads from the buffer. */
	pb_istream_t stream = pb_istream_from_buffer((const pb_byte_t *)inBuffer, inSize);

	/* Now we are ready to decode the message. */
	status = pb_decode(&stream, {{cookiecutter.pb_msg_type}}_fields, &pbMsg); // TODO: Assumes [type]_fields is a standard

	/* Check for errors... */
	if (!status)
	{
		return 0;
	}
	{% for pb_var, msg_var in cookiecutter.var_names.iteritems() %}
	inOutObject->{{msg_var}} = pbMsg.{{pb_var}};{% endfor %}

	return sizeof({{cookiecutter.msg_type}});
}
