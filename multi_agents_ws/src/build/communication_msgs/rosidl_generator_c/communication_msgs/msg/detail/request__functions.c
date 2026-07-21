// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from communication_msgs:msg/Request.idl
// generated code does not contain a copyright notice
#include "communication_msgs/msg/detail/request__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `to`
// Member `action_name`
#include "rosidl_runtime_c/string_functions.h"

bool
communication_msgs__msg__Request__init(communication_msgs__msg__Request * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    communication_msgs__msg__Request__fini(msg);
    return false;
  }
  // id
  // to
  if (!rosidl_runtime_c__String__init(&msg->to)) {
    communication_msgs__msg__Request__fini(msg);
    return false;
  }
  // action_name
  if (!rosidl_runtime_c__String__init(&msg->action_name)) {
    communication_msgs__msg__Request__fini(msg);
    return false;
  }
  return true;
}

void
communication_msgs__msg__Request__fini(communication_msgs__msg__Request * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // id
  // to
  rosidl_runtime_c__String__fini(&msg->to);
  // action_name
  rosidl_runtime_c__String__fini(&msg->action_name);
}

bool
communication_msgs__msg__Request__are_equal(const communication_msgs__msg__Request * lhs, const communication_msgs__msg__Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // to
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->to), &(rhs->to)))
  {
    return false;
  }
  // action_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->action_name), &(rhs->action_name)))
  {
    return false;
  }
  return true;
}

bool
communication_msgs__msg__Request__copy(
  const communication_msgs__msg__Request * input,
  communication_msgs__msg__Request * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // id
  output->id = input->id;
  // to
  if (!rosidl_runtime_c__String__copy(
      &(input->to), &(output->to)))
  {
    return false;
  }
  // action_name
  if (!rosidl_runtime_c__String__copy(
      &(input->action_name), &(output->action_name)))
  {
    return false;
  }
  return true;
}

communication_msgs__msg__Request *
communication_msgs__msg__Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__msg__Request * msg = (communication_msgs__msg__Request *)allocator.allocate(sizeof(communication_msgs__msg__Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__msg__Request));
  bool success = communication_msgs__msg__Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__msg__Request__destroy(communication_msgs__msg__Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__msg__Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__msg__Request__Sequence__init(communication_msgs__msg__Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__msg__Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__msg__Request)) {
      return false;
    }
    data = (communication_msgs__msg__Request *)allocator.zero_allocate(size, sizeof(communication_msgs__msg__Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__msg__Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__msg__Request__fini(&data[i - 1]);
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
communication_msgs__msg__Request__Sequence__fini(communication_msgs__msg__Request__Sequence * array)
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
      communication_msgs__msg__Request__fini(&array->data[i]);
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

communication_msgs__msg__Request__Sequence *
communication_msgs__msg__Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__msg__Request__Sequence * array = (communication_msgs__msg__Request__Sequence *)allocator.allocate(sizeof(communication_msgs__msg__Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__msg__Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__msg__Request__Sequence__destroy(communication_msgs__msg__Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__msg__Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__msg__Request__Sequence__are_equal(const communication_msgs__msg__Request__Sequence * lhs, const communication_msgs__msg__Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__msg__Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__msg__Request__Sequence__copy(
  const communication_msgs__msg__Request__Sequence * input,
  communication_msgs__msg__Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__msg__Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__msg__Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__msg__Request * data =
      (communication_msgs__msg__Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__msg__Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__msg__Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__msg__Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
