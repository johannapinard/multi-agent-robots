#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__srv__GetPose_Request() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__srv__GetPose_Request__init(msg: *mut GetPose_Request) -> bool;
    fn communication_msgs__srv__GetPose_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPose_Request>, size: usize) -> bool;
    fn communication_msgs__srv__GetPose_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPose_Request>);
    fn communication_msgs__srv__GetPose_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPose_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPose_Request>) -> bool;
}

// Corresponds to communication_msgs__srv__GetPose_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPose_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub item: rosidl_runtime_rs::String,

}



impl Default for GetPose_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__srv__GetPose_Request__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__srv__GetPose_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPose_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__srv__GetPose_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__srv__GetPose_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__srv__GetPose_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPose_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPose_Request where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/srv/GetPose_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__srv__GetPose_Request() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__srv__GetPose_Response() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__srv__GetPose_Response__init(msg: *mut GetPose_Response) -> bool;
    fn communication_msgs__srv__GetPose_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GetPose_Response>, size: usize) -> bool;
    fn communication_msgs__srv__GetPose_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GetPose_Response>);
    fn communication_msgs__srv__GetPose_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GetPose_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GetPose_Response>) -> bool;
}

// Corresponds to communication_msgs__srv__GetPose_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPose_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub color: rosidl_runtime_rs::String,

}



impl Default for GetPose_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__srv__GetPose_Response__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__srv__GetPose_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GetPose_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__srv__GetPose_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__srv__GetPose_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__srv__GetPose_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GetPose_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GetPose_Response where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/srv/GetPose_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__srv__GetPose_Response() }
  }
}






#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__communication_msgs__srv__GetPose() -> *const std::ffi::c_void;
}

// Corresponds to communication_msgs__srv__GetPose
#[allow(missing_docs, non_camel_case_types)]
pub struct GetPose;

impl rosidl_runtime_rs::Service for GetPose {
    type Request = GetPose_Request;
    type Response = GetPose_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__communication_msgs__srv__GetPose() }
    }
}


