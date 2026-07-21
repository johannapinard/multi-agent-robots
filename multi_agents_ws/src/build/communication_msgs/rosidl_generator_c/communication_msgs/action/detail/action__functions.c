// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from communication_msgs:action/Action.idl
// generated code does not contain a copyright notice
#include "communication_msgs/action/detail/action__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"

bool
communication_msgs__action__Action_Goal__init(communication_msgs__action__Action_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    communication_msgs__action__Action_Goal__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_Goal__fini(communication_msgs__action__Action_Goal * msg)
{
  if (!msg) {
    return;
  }
  // type
  rosidl_runtime_c__String__fini(&msg->type);
}

bool
communication_msgs__action__Action_Goal__are_equal(const communication_msgs__action__Action_Goal * lhs, const communication_msgs__action__Action_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_Goal__copy(
  const communication_msgs__action__Action_Goal * input,
  communication_msgs__action__Action_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_Goal *
communication_msgs__action__Action_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Goal * msg = (communication_msgs__action__Action_Goal *)allocator.allocate(sizeof(communication_msgs__action__Action_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_Goal));
  bool success = communication_msgs__action__Action_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_Goal__destroy(communication_msgs__action__Action_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_Goal__Sequence__init(communication_msgs__action__Action_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Goal * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_Goal)) {
      return false;
    }
    data = (communication_msgs__action__Action_Goal *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_Goal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_Goal__Sequence__fini(communication_msgs__action__Action_Goal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_Goal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_Goal__Sequence *
communication_msgs__action__Action_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Goal__Sequence * array = (communication_msgs__action__Action_Goal__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_Goal__Sequence__destroy(communication_msgs__action__Action_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_Goal__Sequence__are_equal(const communication_msgs__action__Action_Goal__Sequence * lhs, const communication_msgs__action__Action_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_Goal__Sequence__copy(
  const communication_msgs__action__Action_Goal__Sequence * input,
  communication_msgs__action__Action_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_Goal)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_Goal * data =
      (communication_msgs__action__Action_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `color`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
communication_msgs__action__Action_Result__init(communication_msgs__action__Action_Result * msg)
{
  if (!msg) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__init(&msg->color)) {
    communication_msgs__action__Action_Result__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_Result__fini(communication_msgs__action__Action_Result * msg)
{
  if (!msg) {
    return;
  }
  // color
  rosidl_runtime_c__String__fini(&msg->color);
}

bool
communication_msgs__action__Action_Result__are_equal(const communication_msgs__action__Action_Result * lhs, const communication_msgs__action__Action_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->color), &(rhs->color)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_Result__copy(
  const communication_msgs__action__Action_Result * input,
  communication_msgs__action__Action_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // color
  if (!rosidl_runtime_c__String__copy(
      &(input->color), &(output->color)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_Result *
communication_msgs__action__Action_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Result * msg = (communication_msgs__action__Action_Result *)allocator.allocate(sizeof(communication_msgs__action__Action_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_Result));
  bool success = communication_msgs__action__Action_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_Result__destroy(communication_msgs__action__Action_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_Result__Sequence__init(communication_msgs__action__Action_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Result * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_Result)) {
      return false;
    }
    data = (communication_msgs__action__Action_Result *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_Result__Sequence__fini(communication_msgs__action__Action_Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_Result__Sequence *
communication_msgs__action__Action_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Result__Sequence * array = (communication_msgs__action__Action_Result__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_Result__Sequence__destroy(communication_msgs__action__Action_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_Result__Sequence__are_equal(const communication_msgs__action__Action_Result__Sequence * lhs, const communication_msgs__action__Action_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_Result__Sequence__copy(
  const communication_msgs__action__Action_Result__Sequence * input,
  communication_msgs__action__Action_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_Result)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_Result * data =
      (communication_msgs__action__Action_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `requested_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
communication_msgs__action__Action_Feedback__init(communication_msgs__action__Action_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // requested_pose
  if (!geometry_msgs__msg__Pose__init(&msg->requested_pose)) {
    communication_msgs__action__Action_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_Feedback__fini(communication_msgs__action__Action_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // requested_pose
  geometry_msgs__msg__Pose__fini(&msg->requested_pose);
}

bool
communication_msgs__action__Action_Feedback__are_equal(const communication_msgs__action__Action_Feedback * lhs, const communication_msgs__action__Action_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // requested_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->requested_pose), &(rhs->requested_pose)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_Feedback__copy(
  const communication_msgs__action__Action_Feedback * input,
  communication_msgs__action__Action_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // requested_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->requested_pose), &(output->requested_pose)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_Feedback *
communication_msgs__action__Action_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Feedback * msg = (communication_msgs__action__Action_Feedback *)allocator.allocate(sizeof(communication_msgs__action__Action_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_Feedback));
  bool success = communication_msgs__action__Action_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_Feedback__destroy(communication_msgs__action__Action_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_Feedback__Sequence__init(communication_msgs__action__Action_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Feedback * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_Feedback)) {
      return false;
    }
    data = (communication_msgs__action__Action_Feedback *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_Feedback__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_Feedback__Sequence__fini(communication_msgs__action__Action_Feedback__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_Feedback__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_Feedback__Sequence *
communication_msgs__action__Action_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_Feedback__Sequence * array = (communication_msgs__action__Action_Feedback__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_Feedback__Sequence__destroy(communication_msgs__action__Action_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_Feedback__Sequence__are_equal(const communication_msgs__action__Action_Feedback__Sequence * lhs, const communication_msgs__action__Action_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_Feedback__Sequence__copy(
  const communication_msgs__action__Action_Feedback__Sequence * input,
  communication_msgs__action__Action_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_Feedback)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_Feedback * data =
      (communication_msgs__action__Action_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "communication_msgs/action/detail/action__functions.h"

bool
communication_msgs__action__Action_SendGoal_Request__init(communication_msgs__action__Action_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    communication_msgs__action__Action_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!communication_msgs__action__Action_Goal__init(&msg->goal)) {
    communication_msgs__action__Action_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_SendGoal_Request__fini(communication_msgs__action__Action_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  communication_msgs__action__Action_Goal__fini(&msg->goal);
}

bool
communication_msgs__action__Action_SendGoal_Request__are_equal(const communication_msgs__action__Action_SendGoal_Request * lhs, const communication_msgs__action__Action_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!communication_msgs__action__Action_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_SendGoal_Request__copy(
  const communication_msgs__action__Action_SendGoal_Request * input,
  communication_msgs__action__Action_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!communication_msgs__action__Action_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_SendGoal_Request *
communication_msgs__action__Action_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Request * msg = (communication_msgs__action__Action_SendGoal_Request *)allocator.allocate(sizeof(communication_msgs__action__Action_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_SendGoal_Request));
  bool success = communication_msgs__action__Action_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_SendGoal_Request__destroy(communication_msgs__action__Action_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_SendGoal_Request__Sequence__init(communication_msgs__action__Action_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_SendGoal_Request)) {
      return false;
    }
    data = (communication_msgs__action__Action_SendGoal_Request *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_SendGoal_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_SendGoal_Request__Sequence__fini(communication_msgs__action__Action_SendGoal_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_SendGoal_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_SendGoal_Request__Sequence *
communication_msgs__action__Action_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Request__Sequence * array = (communication_msgs__action__Action_SendGoal_Request__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_SendGoal_Request__Sequence__destroy(communication_msgs__action__Action_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_SendGoal_Request__Sequence__are_equal(const communication_msgs__action__Action_SendGoal_Request__Sequence * lhs, const communication_msgs__action__Action_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_SendGoal_Request__Sequence__copy(
  const communication_msgs__action__Action_SendGoal_Request__Sequence * input,
  communication_msgs__action__Action_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_SendGoal_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_SendGoal_Request * data =
      (communication_msgs__action__Action_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
communication_msgs__action__Action_SendGoal_Response__init(communication_msgs__action__Action_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    communication_msgs__action__Action_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_SendGoal_Response__fini(communication_msgs__action__Action_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
communication_msgs__action__Action_SendGoal_Response__are_equal(const communication_msgs__action__Action_SendGoal_Response * lhs, const communication_msgs__action__Action_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_SendGoal_Response__copy(
  const communication_msgs__action__Action_SendGoal_Response * input,
  communication_msgs__action__Action_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_SendGoal_Response *
communication_msgs__action__Action_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Response * msg = (communication_msgs__action__Action_SendGoal_Response *)allocator.allocate(sizeof(communication_msgs__action__Action_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_SendGoal_Response));
  bool success = communication_msgs__action__Action_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_SendGoal_Response__destroy(communication_msgs__action__Action_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_SendGoal_Response__Sequence__init(communication_msgs__action__Action_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_SendGoal_Response)) {
      return false;
    }
    data = (communication_msgs__action__Action_SendGoal_Response *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_SendGoal_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_SendGoal_Response__Sequence__fini(communication_msgs__action__Action_SendGoal_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_SendGoal_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_SendGoal_Response__Sequence *
communication_msgs__action__Action_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Response__Sequence * array = (communication_msgs__action__Action_SendGoal_Response__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_SendGoal_Response__Sequence__destroy(communication_msgs__action__Action_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_SendGoal_Response__Sequence__are_equal(const communication_msgs__action__Action_SendGoal_Response__Sequence * lhs, const communication_msgs__action__Action_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_SendGoal_Response__Sequence__copy(
  const communication_msgs__action__Action_SendGoal_Response__Sequence * input,
  communication_msgs__action__Action_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_SendGoal_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_SendGoal_Response * data =
      (communication_msgs__action__Action_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "communication_msgs/action/detail/action__functions.h"

bool
communication_msgs__action__Action_SendGoal_Event__init(communication_msgs__action__Action_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    communication_msgs__action__Action_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!communication_msgs__action__Action_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    communication_msgs__action__Action_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!communication_msgs__action__Action_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    communication_msgs__action__Action_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_SendGoal_Event__fini(communication_msgs__action__Action_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  communication_msgs__action__Action_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  communication_msgs__action__Action_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
communication_msgs__action__Action_SendGoal_Event__are_equal(const communication_msgs__action__Action_SendGoal_Event * lhs, const communication_msgs__action__Action_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!communication_msgs__action__Action_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!communication_msgs__action__Action_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_SendGoal_Event__copy(
  const communication_msgs__action__Action_SendGoal_Event * input,
  communication_msgs__action__Action_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!communication_msgs__action__Action_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!communication_msgs__action__Action_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_SendGoal_Event *
communication_msgs__action__Action_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Event * msg = (communication_msgs__action__Action_SendGoal_Event *)allocator.allocate(sizeof(communication_msgs__action__Action_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_SendGoal_Event));
  bool success = communication_msgs__action__Action_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_SendGoal_Event__destroy(communication_msgs__action__Action_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_SendGoal_Event__Sequence__init(communication_msgs__action__Action_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_SendGoal_Event)) {
      return false;
    }
    data = (communication_msgs__action__Action_SendGoal_Event *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_SendGoal_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_SendGoal_Event__Sequence__fini(communication_msgs__action__Action_SendGoal_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_SendGoal_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_SendGoal_Event__Sequence *
communication_msgs__action__Action_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_SendGoal_Event__Sequence * array = (communication_msgs__action__Action_SendGoal_Event__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_SendGoal_Event__Sequence__destroy(communication_msgs__action__Action_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_SendGoal_Event__Sequence__are_equal(const communication_msgs__action__Action_SendGoal_Event__Sequence * lhs, const communication_msgs__action__Action_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_SendGoal_Event__Sequence__copy(
  const communication_msgs__action__Action_SendGoal_Event__Sequence * input,
  communication_msgs__action__Action_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_SendGoal_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_SendGoal_Event * data =
      (communication_msgs__action__Action_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
communication_msgs__action__Action_GetResult_Request__init(communication_msgs__action__Action_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    communication_msgs__action__Action_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_GetResult_Request__fini(communication_msgs__action__Action_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
communication_msgs__action__Action_GetResult_Request__are_equal(const communication_msgs__action__Action_GetResult_Request * lhs, const communication_msgs__action__Action_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_GetResult_Request__copy(
  const communication_msgs__action__Action_GetResult_Request * input,
  communication_msgs__action__Action_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_GetResult_Request *
communication_msgs__action__Action_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Request * msg = (communication_msgs__action__Action_GetResult_Request *)allocator.allocate(sizeof(communication_msgs__action__Action_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_GetResult_Request));
  bool success = communication_msgs__action__Action_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_GetResult_Request__destroy(communication_msgs__action__Action_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_GetResult_Request__Sequence__init(communication_msgs__action__Action_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_GetResult_Request)) {
      return false;
    }
    data = (communication_msgs__action__Action_GetResult_Request *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_GetResult_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_GetResult_Request__Sequence__fini(communication_msgs__action__Action_GetResult_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_GetResult_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_GetResult_Request__Sequence *
communication_msgs__action__Action_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Request__Sequence * array = (communication_msgs__action__Action_GetResult_Request__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_GetResult_Request__Sequence__destroy(communication_msgs__action__Action_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_GetResult_Request__Sequence__are_equal(const communication_msgs__action__Action_GetResult_Request__Sequence * lhs, const communication_msgs__action__Action_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_GetResult_Request__Sequence__copy(
  const communication_msgs__action__Action_GetResult_Request__Sequence * input,
  communication_msgs__action__Action_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_GetResult_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_GetResult_Request * data =
      (communication_msgs__action__Action_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "communication_msgs/action/detail/action__functions.h"

bool
communication_msgs__action__Action_GetResult_Response__init(communication_msgs__action__Action_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!communication_msgs__action__Action_Result__init(&msg->result)) {
    communication_msgs__action__Action_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_GetResult_Response__fini(communication_msgs__action__Action_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  communication_msgs__action__Action_Result__fini(&msg->result);
}

bool
communication_msgs__action__Action_GetResult_Response__are_equal(const communication_msgs__action__Action_GetResult_Response * lhs, const communication_msgs__action__Action_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!communication_msgs__action__Action_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_GetResult_Response__copy(
  const communication_msgs__action__Action_GetResult_Response * input,
  communication_msgs__action__Action_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!communication_msgs__action__Action_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_GetResult_Response *
communication_msgs__action__Action_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Response * msg = (communication_msgs__action__Action_GetResult_Response *)allocator.allocate(sizeof(communication_msgs__action__Action_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_GetResult_Response));
  bool success = communication_msgs__action__Action_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_GetResult_Response__destroy(communication_msgs__action__Action_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_GetResult_Response__Sequence__init(communication_msgs__action__Action_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_GetResult_Response)) {
      return false;
    }
    data = (communication_msgs__action__Action_GetResult_Response *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_GetResult_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_GetResult_Response__Sequence__fini(communication_msgs__action__Action_GetResult_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_GetResult_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_GetResult_Response__Sequence *
communication_msgs__action__Action_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Response__Sequence * array = (communication_msgs__action__Action_GetResult_Response__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_GetResult_Response__Sequence__destroy(communication_msgs__action__Action_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_GetResult_Response__Sequence__are_equal(const communication_msgs__action__Action_GetResult_Response__Sequence * lhs, const communication_msgs__action__Action_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_GetResult_Response__Sequence__copy(
  const communication_msgs__action__Action_GetResult_Response__Sequence * input,
  communication_msgs__action__Action_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_GetResult_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_GetResult_Response * data =
      (communication_msgs__action__Action_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "communication_msgs/action/detail/action__functions.h"

bool
communication_msgs__action__Action_GetResult_Event__init(communication_msgs__action__Action_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    communication_msgs__action__Action_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!communication_msgs__action__Action_GetResult_Request__Sequence__init(&msg->request, 0)) {
    communication_msgs__action__Action_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!communication_msgs__action__Action_GetResult_Response__Sequence__init(&msg->response, 0)) {
    communication_msgs__action__Action_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_GetResult_Event__fini(communication_msgs__action__Action_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  communication_msgs__action__Action_GetResult_Request__Sequence__fini(&msg->request);
  // response
  communication_msgs__action__Action_GetResult_Response__Sequence__fini(&msg->response);
}

bool
communication_msgs__action__Action_GetResult_Event__are_equal(const communication_msgs__action__Action_GetResult_Event * lhs, const communication_msgs__action__Action_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!communication_msgs__action__Action_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!communication_msgs__action__Action_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_GetResult_Event__copy(
  const communication_msgs__action__Action_GetResult_Event * input,
  communication_msgs__action__Action_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!communication_msgs__action__Action_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!communication_msgs__action__Action_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_GetResult_Event *
communication_msgs__action__Action_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Event * msg = (communication_msgs__action__Action_GetResult_Event *)allocator.allocate(sizeof(communication_msgs__action__Action_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_GetResult_Event));
  bool success = communication_msgs__action__Action_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_GetResult_Event__destroy(communication_msgs__action__Action_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_GetResult_Event__Sequence__init(communication_msgs__action__Action_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_GetResult_Event)) {
      return false;
    }
    data = (communication_msgs__action__Action_GetResult_Event *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_GetResult_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_GetResult_Event__Sequence__fini(communication_msgs__action__Action_GetResult_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_GetResult_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_GetResult_Event__Sequence *
communication_msgs__action__Action_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_GetResult_Event__Sequence * array = (communication_msgs__action__Action_GetResult_Event__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_GetResult_Event__Sequence__destroy(communication_msgs__action__Action_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_GetResult_Event__Sequence__are_equal(const communication_msgs__action__Action_GetResult_Event__Sequence * lhs, const communication_msgs__action__Action_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_GetResult_Event__Sequence__copy(
  const communication_msgs__action__Action_GetResult_Event__Sequence * input,
  communication_msgs__action__Action_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_GetResult_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_GetResult_Event * data =
      (communication_msgs__action__Action_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "communication_msgs/action/detail/action__functions.h"

bool
communication_msgs__action__Action_FeedbackMessage__init(communication_msgs__action__Action_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    communication_msgs__action__Action_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!communication_msgs__action__Action_Feedback__init(&msg->feedback)) {
    communication_msgs__action__Action_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__action__Action_FeedbackMessage__fini(communication_msgs__action__Action_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  communication_msgs__action__Action_Feedback__fini(&msg->feedback);
}

bool
communication_msgs__action__Action_FeedbackMessage__are_equal(const communication_msgs__action__Action_FeedbackMessage * lhs, const communication_msgs__action__Action_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!communication_msgs__action__Action_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__action__Action_FeedbackMessage__copy(
  const communication_msgs__action__Action_FeedbackMessage * input,
  communication_msgs__action__Action_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!communication_msgs__action__Action_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

communication_msgs__action__Action_FeedbackMessage *
communication_msgs__action__Action_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_FeedbackMessage * msg = (communication_msgs__action__Action_FeedbackMessage *)allocator.allocate(sizeof(communication_msgs__action__Action_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__action__Action_FeedbackMessage));
  bool success = communication_msgs__action__Action_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__action__Action_FeedbackMessage__destroy(communication_msgs__action__Action_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__action__Action_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__action__Action_FeedbackMessage__Sequence__init(communication_msgs__action__Action_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_FeedbackMessage * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__action__Action_FeedbackMessage)) {
      return false;
    }
    data = (communication_msgs__action__Action_FeedbackMessage *)allocator.zero_allocate(size, sizeof(communication_msgs__action__Action_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__action__Action_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__action__Action_FeedbackMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
communication_msgs__action__Action_FeedbackMessage__Sequence__fini(communication_msgs__action__Action_FeedbackMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      communication_msgs__action__Action_FeedbackMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

communication_msgs__action__Action_FeedbackMessage__Sequence *
communication_msgs__action__Action_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__action__Action_FeedbackMessage__Sequence * array = (communication_msgs__action__Action_FeedbackMessage__Sequence *)allocator.allocate(sizeof(communication_msgs__action__Action_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__action__Action_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__action__Action_FeedbackMessage__Sequence__destroy(communication_msgs__action__Action_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__action__Action_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__action__Action_FeedbackMessage__Sequence__are_equal(const communication_msgs__action__Action_FeedbackMessage__Sequence * lhs, const communication_msgs__action__Action_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__action__Action_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__action__Action_FeedbackMessage__Sequence__copy(
  const communication_msgs__action__Action_FeedbackMessage__Sequence * input,
  communication_msgs__action__Action_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__action__Action_FeedbackMessage)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__action__Action_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__action__Action_FeedbackMessage * data =
      (communication_msgs__action__Action_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__action__Action_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__action__Action_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__action__Action_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
