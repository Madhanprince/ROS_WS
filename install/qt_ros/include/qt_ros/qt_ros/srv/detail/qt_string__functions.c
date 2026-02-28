// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qt_ros:srv/QtString.idl
// generated code does not contain a copyright notice
#include "qt_ros/srv/detail/qt_string__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `req`
#include "rosidl_runtime_c/string_functions.h"

bool
qt_ros__srv__QtString_Request__init(qt_ros__srv__QtString_Request * msg)
{
  if (!msg) {
    return false;
  }
  // req
  if (!rosidl_runtime_c__String__init(&msg->req)) {
    qt_ros__srv__QtString_Request__fini(msg);
    return false;
  }
  return true;
}

void
qt_ros__srv__QtString_Request__fini(qt_ros__srv__QtString_Request * msg)
{
  if (!msg) {
    return;
  }
  // req
  rosidl_runtime_c__String__fini(&msg->req);
}

bool
qt_ros__srv__QtString_Request__are_equal(const qt_ros__srv__QtString_Request * lhs, const qt_ros__srv__QtString_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // req
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->req), &(rhs->req)))
  {
    return false;
  }
  return true;
}

bool
qt_ros__srv__QtString_Request__copy(
  const qt_ros__srv__QtString_Request * input,
  qt_ros__srv__QtString_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // req
  if (!rosidl_runtime_c__String__copy(
      &(input->req), &(output->req)))
  {
    return false;
  }
  return true;
}

qt_ros__srv__QtString_Request *
qt_ros__srv__QtString_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_ros__srv__QtString_Request * msg = (qt_ros__srv__QtString_Request *)allocator.allocate(sizeof(qt_ros__srv__QtString_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qt_ros__srv__QtString_Request));
  bool success = qt_ros__srv__QtString_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qt_ros__srv__QtString_Request__destroy(qt_ros__srv__QtString_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qt_ros__srv__QtString_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qt_ros__srv__QtString_Request__Sequence__init(qt_ros__srv__QtString_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_ros__srv__QtString_Request * data = NULL;

  if (size) {
    data = (qt_ros__srv__QtString_Request *)allocator.zero_allocate(size, sizeof(qt_ros__srv__QtString_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qt_ros__srv__QtString_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qt_ros__srv__QtString_Request__fini(&data[i - 1]);
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
qt_ros__srv__QtString_Request__Sequence__fini(qt_ros__srv__QtString_Request__Sequence * array)
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
      qt_ros__srv__QtString_Request__fini(&array->data[i]);
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

qt_ros__srv__QtString_Request__Sequence *
qt_ros__srv__QtString_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_ros__srv__QtString_Request__Sequence * array = (qt_ros__srv__QtString_Request__Sequence *)allocator.allocate(sizeof(qt_ros__srv__QtString_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qt_ros__srv__QtString_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qt_ros__srv__QtString_Request__Sequence__destroy(qt_ros__srv__QtString_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qt_ros__srv__QtString_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qt_ros__srv__QtString_Request__Sequence__are_equal(const qt_ros__srv__QtString_Request__Sequence * lhs, const qt_ros__srv__QtString_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qt_ros__srv__QtString_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qt_ros__srv__QtString_Request__Sequence__copy(
  const qt_ros__srv__QtString_Request__Sequence * input,
  qt_ros__srv__QtString_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qt_ros__srv__QtString_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qt_ros__srv__QtString_Request * data =
      (qt_ros__srv__QtString_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qt_ros__srv__QtString_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qt_ros__srv__QtString_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qt_ros__srv__QtString_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
qt_ros__srv__QtString_Response__init(qt_ros__srv__QtString_Response * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    qt_ros__srv__QtString_Response__fini(msg);
    return false;
  }
  return true;
}

void
qt_ros__srv__QtString_Response__fini(qt_ros__srv__QtString_Response * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
qt_ros__srv__QtString_Response__are_equal(const qt_ros__srv__QtString_Response * lhs, const qt_ros__srv__QtString_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
qt_ros__srv__QtString_Response__copy(
  const qt_ros__srv__QtString_Response * input,
  qt_ros__srv__QtString_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

qt_ros__srv__QtString_Response *
qt_ros__srv__QtString_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_ros__srv__QtString_Response * msg = (qt_ros__srv__QtString_Response *)allocator.allocate(sizeof(qt_ros__srv__QtString_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qt_ros__srv__QtString_Response));
  bool success = qt_ros__srv__QtString_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qt_ros__srv__QtString_Response__destroy(qt_ros__srv__QtString_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qt_ros__srv__QtString_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qt_ros__srv__QtString_Response__Sequence__init(qt_ros__srv__QtString_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_ros__srv__QtString_Response * data = NULL;

  if (size) {
    data = (qt_ros__srv__QtString_Response *)allocator.zero_allocate(size, sizeof(qt_ros__srv__QtString_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qt_ros__srv__QtString_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qt_ros__srv__QtString_Response__fini(&data[i - 1]);
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
qt_ros__srv__QtString_Response__Sequence__fini(qt_ros__srv__QtString_Response__Sequence * array)
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
      qt_ros__srv__QtString_Response__fini(&array->data[i]);
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

qt_ros__srv__QtString_Response__Sequence *
qt_ros__srv__QtString_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_ros__srv__QtString_Response__Sequence * array = (qt_ros__srv__QtString_Response__Sequence *)allocator.allocate(sizeof(qt_ros__srv__QtString_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qt_ros__srv__QtString_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qt_ros__srv__QtString_Response__Sequence__destroy(qt_ros__srv__QtString_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qt_ros__srv__QtString_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qt_ros__srv__QtString_Response__Sequence__are_equal(const qt_ros__srv__QtString_Response__Sequence * lhs, const qt_ros__srv__QtString_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qt_ros__srv__QtString_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qt_ros__srv__QtString_Response__Sequence__copy(
  const qt_ros__srv__QtString_Response__Sequence * input,
  qt_ros__srv__QtString_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(qt_ros__srv__QtString_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qt_ros__srv__QtString_Response * data =
      (qt_ros__srv__QtString_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qt_ros__srv__QtString_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qt_ros__srv__QtString_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qt_ros__srv__QtString_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
