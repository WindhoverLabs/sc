# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_HS_CDSData_t.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='_py_HS_CDSData_t.proto',
  package='',
  serialized_pb=_b('\n\x16_py_HS_CDSData_t.proto\"o\n\x0fHS_CDSData_t_pb\x12\x1a\n\x12ResetsPerformedNot\x18\x01 \x02(\r\x12\x11\n\tMaxResets\x18\x02 \x02(\r\x12\x14\n\x0cMaxResetsNot\x18\x03 \x02(\r\x12\x17\n\x0fResetsPerformed\x18\x04 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_HS_CDSDATA_T_PB = _descriptor.Descriptor(
  name='HS_CDSData_t_pb',
  full_name='HS_CDSData_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ResetsPerformedNot', full_name='HS_CDSData_t_pb.ResetsPerformedNot', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MaxResets', full_name='HS_CDSData_t_pb.MaxResets', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MaxResetsNot', full_name='HS_CDSData_t_pb.MaxResetsNot', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ResetsPerformed', full_name='HS_CDSData_t_pb.ResetsPerformed', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=26,
  serialized_end=137,
)

DESCRIPTOR.message_types_by_name['HS_CDSData_t_pb'] = _HS_CDSDATA_T_PB

HS_CDSData_t_pb = _reflection.GeneratedProtocolMessageType('HS_CDSData_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _HS_CDSDATA_T_PB,
  __module__ = '_py_HS_CDSData_t_pb2'
  # @@protoc_insertion_point(class_scope:HS_CDSData_t_pb)
  ))
_sym_db.RegisterMessage(HS_CDSData_t_pb)


# @@protoc_insertion_point(module_scope)