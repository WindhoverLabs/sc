""" This file was autogenerated from template version 0.0.0.1 and autogenerator version {{cookiecutter.autogen_version}} """
{% for app, app_data in cookiecutter.Airliner.apps.iteritems() -%}
    {% for airliner_msg, proto_data in app_data.proto_msgs.iteritems() %}
import {{proto_data.proto_msg[:-3]}}_pb2{% endfor %}{% endfor %}


proto_msg_map = {
    {%- for app, app_data in cookiecutter.Airliner.apps.iteritems() -%}
        {%- for airliner_msg, proto_data in app_data.proto_msgs.iteritems() %}
    "{{airliner_msg}}": {{proto_data.proto_msg[:-3]}}_pb2.{{proto_data.proto_msg}},{% endfor %}{% endfor %}
}
