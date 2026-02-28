#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "qt_ros::qt_ros__rosidl_generator_py" for configuration ""
set_property(TARGET qt_ros::qt_ros__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(qt_ros::qt_ros__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libqt_ros__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libqt_ros__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS qt_ros::qt_ros__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_qt_ros::qt_ros__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libqt_ros__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
