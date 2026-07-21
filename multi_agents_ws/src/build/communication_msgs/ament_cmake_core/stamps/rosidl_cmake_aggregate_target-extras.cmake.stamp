# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target communication_msgs::communication_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${communication_msgs_TARGETS}.
if(communication_msgs_TARGETS AND NOT TARGET communication_msgs::communication_msgs)
  add_library(communication_msgs::communication_msgs INTERFACE IMPORTED)
  set_target_properties(communication_msgs::communication_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${communication_msgs_TARGETS}")
endif()
