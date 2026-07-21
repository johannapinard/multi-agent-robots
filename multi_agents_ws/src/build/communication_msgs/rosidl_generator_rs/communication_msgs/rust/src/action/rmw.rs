
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_Goal() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_Goal__init(msg: *mut Action_Goal) -> bool;
    fn communication_msgs__action__Action_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_Goal>, size: usize) -> bool;
    fn communication_msgs__action__Action_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_Goal>);
    fn communication_msgs__action__Action_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_Goal>) -> bool;
}

// Corresponds to communication_msgs__action__Action_Goal
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_Goal {
    /// communication_msg/Search, communication_msg/Pick
    pub type_: rosidl_runtime_rs::String,

}



impl Default for Action_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_Goal__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_Goal() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_Result() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_Result__init(msg: *mut Action_Result) -> bool;
    fn communication_msgs__action__Action_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_Result>, size: usize) -> bool;
    fn communication_msgs__action__Action_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_Result>);
    fn communication_msgs__action__Action_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_Result>) -> bool;
}

// Corresponds to communication_msgs__action__Action_Result
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_Result {

    // This member is not documented.
    #[allow(missing_docs)]
    pub color: rosidl_runtime_rs::String,

}



impl Default for Action_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_Result__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_Result where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_Result() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_Feedback__init(msg: *mut Action_Feedback) -> bool;
    fn communication_msgs__action__Action_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_Feedback>, size: usize) -> bool;
    fn communication_msgs__action__Action_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_Feedback>);
    fn communication_msgs__action__Action_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_Feedback>) -> bool;
}

// Corresponds to communication_msgs__action__Action_Feedback
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_Feedback {

    // This member is not documented.
    #[allow(missing_docs)]
    pub requested_pose: geometry_msgs::msg::rmw::Pose,

}



impl Default for Action_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_Feedback__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_Feedback() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_FeedbackMessage__init(msg: *mut Action_FeedbackMessage) -> bool;
    fn communication_msgs__action__Action_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_FeedbackMessage>, size: usize) -> bool;
    fn communication_msgs__action__Action_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_FeedbackMessage>);
    fn communication_msgs__action__Action_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_FeedbackMessage>) -> bool;
}

// Corresponds to communication_msgs__action__Action_FeedbackMessage
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_FeedbackMessage {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub feedback: super::super::action::rmw::Action_Feedback,

}



impl Default for Action_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_FeedbackMessage() }
  }
}




#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_SendGoal_Request__init(msg: *mut Action_SendGoal_Request) -> bool;
    fn communication_msgs__action__Action_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_SendGoal_Request>, size: usize) -> bool;
    fn communication_msgs__action__Action_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_SendGoal_Request>);
    fn communication_msgs__action__Action_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_SendGoal_Request>) -> bool;
}

// Corresponds to communication_msgs__action__Action_SendGoal_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_SendGoal_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,


    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: super::super::action::rmw::Action_Goal,

}



impl Default for Action_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_SendGoal_Request() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_SendGoal_Response__init(msg: *mut Action_SendGoal_Response) -> bool;
    fn communication_msgs__action__Action_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_SendGoal_Response>, size: usize) -> bool;
    fn communication_msgs__action__Action_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_SendGoal_Response>);
    fn communication_msgs__action__Action_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_SendGoal_Response>) -> bool;
}

// Corresponds to communication_msgs__action__Action_SendGoal_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_SendGoal_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub accepted: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub stamp: builtin_interfaces::msg::rmw::Time,

}



impl Default for Action_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_SendGoal_Response() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_GetResult_Request__init(msg: *mut Action_GetResult_Request) -> bool;
    fn communication_msgs__action__Action_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_GetResult_Request>, size: usize) -> bool;
    fn communication_msgs__action__Action_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_GetResult_Request>);
    fn communication_msgs__action__Action_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_GetResult_Request>) -> bool;
}

// Corresponds to communication_msgs__action__Action_GetResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_GetResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,

}



impl Default for Action_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_GetResult_Request() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__action__Action_GetResult_Response__init(msg: *mut Action_GetResult_Response) -> bool;
    fn communication_msgs__action__Action_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Action_GetResult_Response>, size: usize) -> bool;
    fn communication_msgs__action__Action_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Action_GetResult_Response>);
    fn communication_msgs__action__Action_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Action_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Action_GetResult_Response>) -> bool;
}

// Corresponds to communication_msgs__action__Action_GetResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Action_GetResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub status: i8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub result: super::super::action::rmw::Action_Result,

}



impl Default for Action_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__action__Action_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__action__Action_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Action_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__action__Action_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Action_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Action_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/action/Action_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__action__Action_GetResult_Response() }
  }
}






#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__communication_msgs__action__Action_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to communication_msgs__action__Action_SendGoal
#[allow(missing_docs, non_camel_case_types)]
pub struct Action_SendGoal;

impl rosidl_runtime_rs::Service for Action_SendGoal {
    type Request = Action_SendGoal_Request;
    type Response = Action_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__communication_msgs__action__Action_SendGoal() }
    }
}




#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__communication_msgs__action__Action_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to communication_msgs__action__Action_GetResult
#[allow(missing_docs, non_camel_case_types)]
pub struct Action_GetResult;

impl rosidl_runtime_rs::Service for Action_GetResult {
    type Request = Action_GetResult_Request;
    type Response = Action_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__communication_msgs__action__Action_GetResult() }
    }
}


