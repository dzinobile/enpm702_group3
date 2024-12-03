# generated from rosidl_generator_py/resource/_idl.py.em
# with input from bot_waypoint_msgs:msg/BotWaypoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BotWaypoint(type):
    """Metaclass of message 'BotWaypoint'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SMALL': 1,
        'MEDIUM': 2,
        'LARGE': 3,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('bot_waypoint_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'bot_waypoint_msgs.msg.BotWaypoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__bot_waypoint
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__bot_waypoint
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__bot_waypoint
            cls._TYPE_SUPPORT = module.type_support_msg__msg__bot_waypoint
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__bot_waypoint

            from geometry_msgs.msg import Pose2D
            if Pose2D.__class__._TYPE_SUPPORT is None:
                Pose2D.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SMALL': cls.__constants['SMALL'],
            'MEDIUM': cls.__constants['MEDIUM'],
            'LARGE': cls.__constants['LARGE'],
        }

    @property
    def SMALL(self):
        """Message constant 'SMALL'."""
        return Metaclass_BotWaypoint.__constants['SMALL']

    @property
    def MEDIUM(self):
        """Message constant 'MEDIUM'."""
        return Metaclass_BotWaypoint.__constants['MEDIUM']

    @property
    def LARGE(self):
        """Message constant 'LARGE'."""
        return Metaclass_BotWaypoint.__constants['LARGE']


class BotWaypoint(metaclass=Metaclass_BotWaypoint):
    """
    Message class 'BotWaypoint'.

    Constants:
      SMALL
      MEDIUM
      LARGE
    """

    __slots__ = [
        '_tolerance',
        '_waypoint',
    ]

    _fields_and_field_types = {
        'tolerance': 'uint8',
        'waypoint': 'geometry_msgs/Pose2D',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose2D'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.tolerance = kwargs.get('tolerance', int())
        from geometry_msgs.msg import Pose2D
        self.waypoint = kwargs.get('waypoint', Pose2D())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.tolerance != other.tolerance:
            return False
        if self.waypoint != other.waypoint:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def tolerance(self):
        """Message field 'tolerance'."""
        return self._tolerance

    @tolerance.setter
    def tolerance(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tolerance' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'tolerance' field must be an unsigned integer in [0, 255]"
        self._tolerance = value

    @builtins.property
    def waypoint(self):
        """Message field 'waypoint'."""
        return self._waypoint

    @waypoint.setter
    def waypoint(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose2D
            assert \
                isinstance(value, Pose2D), \
                "The 'waypoint' field must be a sub message of type 'Pose2D'"
        self._waypoint = value
