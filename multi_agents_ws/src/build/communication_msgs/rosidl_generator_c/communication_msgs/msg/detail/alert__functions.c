// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from communication_msgs:msg/Alert.idl
// generated code does not contain a copyright notice
#include "communication_msgs/msg/detail/alert__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
communication_msgs__msg__Alert__init(communication_msgs__msg__Alert * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    communication_msgs__msg__Alert__fini(msg);
    return false;
  }
  // code
  return true;
}

void
communication_msgs__msg__Alert__fini(communication_msgs__msg__Alert * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // code
}

bool
communication_msgs__msg__Alert__are_equal(const communication_msgs__msg__Alert * lhs, const communication_msgs__msg__Alert * rhs)
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
  // code
  if (lhs->code != rhs->code) {
    return false;
  }
  return true;
}

bool
communication_msgs__msg__Alert__copy(
  const communication_msgs__msg__Alert * input,
  communication_msgs__msg__Alert * output)
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
  // code
  output->code = input->code;
  return true;
}

communication_msgs__msg__Alert *
communication_msgs__msg__Alert__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__msg__Alert * msg = (communication_msgs__msg__Alert *)allocator.allocate(sizeof(communication_msgs__msg__Alert), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(communication_msgs__msg__Alert));
  bool success = communication_msgs__msg__Alert__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
communication_msgs__msg__Alert__destroy(communication_msgs__msg__Alert * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    communication_msgs__msg__Alert__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
communication_msgs__msg__Alert__Sequence__init(communication_msgs__msg__Alert__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__msg__Alert * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(communication_msgs__msg__Alert)) {
      return false;
    }
    data = (communication_msgs__msg__Alert *)allocator.zero_allocate(size, sizeof(communication_msgs__msg__Alert), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = communication_msgs__msg__Alert__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        communication_msgs__msg__Alert__fini(&data[i - 1]);
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
communication_msgs__msg__Alert__Sequence__fini(communication_msgs__msg__Alert__Sequence * array)
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
      communication_msgs__msg__Alert__fini(&array->data[i]);
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

communication_msgs__msg__Alert__Sequence *
communication_msgs__msg__Alert__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  communication_msgs__msg__Alert__Sequence * array = (communication_msgs__msg__Alert__Sequence *)allocator.allocate(sizeof(communication_msgs__msg__Alert__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = communication_msgs__msg__Alert__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
communication_msgs__msg__Alert__Sequence__destroy(communication_msgs__msg__Alert__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    communication_msgs__msg__Alert__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
communication_msgs__msg__Alert__Sequence__are_equal(const communication_msgs__msg__Alert__Sequence * lhs, const communication_msgs__msg__Alert__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!communication_msgs__msg__Alert__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
communication_msgs__msg__Alert__Sequence__copy(
  const communication_msgs__msg__Alert__Sequence * input,
  communication_msgs__msg__Alert__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(communication_msgs__msg__Alert)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(communication_msgs__msg__Alert);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    communication_msgs__msg__Alert * data =
      (communication_msgs__msg__Alert *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!communication_msgs__msg__Alert__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          communication_msgs__msg__Alert__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!communication_msgs__msg__Alert__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
