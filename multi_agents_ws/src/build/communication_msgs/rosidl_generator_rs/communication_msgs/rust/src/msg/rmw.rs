#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Alert() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__msg__Alert__init(msg: *mut Alert) -> bool;
    fn communication_msgs__msg__Alert__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Alert>, size: usize) -> bool;
    fn communication_msgs__msg__Alert__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Alert>);
    fn communication_msgs__msg__Alert__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Alert>, out_seq: *mut rosidl_runtime_rs::Sequence<Alert>) -> bool;
}

// Corresponds to communication_msgs__msg__Alert
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Message sent to all robots

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Alert {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// 1: battery below 20%, 2: sensor not available
    pub code: i32,

}



impl Default for Alert {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__msg__Alert__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__msg__Alert__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Alert {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Alert__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Alert__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Alert__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Alert {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Alert where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/msg/Alert";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Alert() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Answer() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__msg__Answer__init(msg: *mut Answer) -> bool;
    fn communication_msgs__msg__Answer__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Answer>, size: usize) -> bool;
    fn communication_msgs__msg__Answer__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Answer>);
    fn communication_msgs__msg__Answer__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Answer>, out_seq: *mut rosidl_runtime_rs::Sequence<Answer>) -> bool;
}

// Corresponds to communication_msgs__msg__Answer
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Answer {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// should be the same as request id
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub to: rosidl_runtime_rs::String,

    /// 0 error, 1 success, 2 ongoing
    pub response_code: i32,

    /// move, scan etc
    pub current_action: rosidl_runtime_rs::String,

    /// human-readable log message
    pub details: rosidl_runtime_rs::String,

}



impl Default for Answer {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__msg__Answer__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__msg__Answer__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Answer {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Answer__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Answer__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Answer__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Answer {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Answer where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/msg/Answer";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Answer() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Info() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__msg__Info__init(msg: *mut Info) -> bool;
    fn communication_msgs__msg__Info__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Info>, size: usize) -> bool;
    fn communication_msgs__msg__Info__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Info>);
    fn communication_msgs__msg__Info__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Info>, out_seq: *mut rosidl_runtime_rs::Sequence<Info>) -> bool;
}

// Corresponds to communication_msgs__msg__Info
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// TODO custom description

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Info {
    /// This is a message that holds data to describe the state of a set of torque controlled joints.
    ///
    /// The state of each joint (revolute or prismatic) is defined by:
    ///  * the position of the joint (rad or m),
    ///  * the velocity of the joint (rad/s or m/s) and
    ///  * the effort that is applied in the joint (Nm or N).
    ///
    /// Each joint is uniquely identified by its name
    /// The header specifies the time at which the joint states were recorded. All the joint states
    /// in one message have to be recorded at the same time.
    ///
    /// This message consists of a multiple arrays, one for each part of the joint state.
    /// The goal is to make each of the fields optional. When e.g. your joints have no
    /// effort associated with them, you can leave the effort array empty.
    ///
    /// All arrays in this message should have the same size, or be empty.
    /// This is the only way to uniquely associate the joint name with the correct
    /// states.
    pub header: std_msgs::msg::rmw::Header,

    /// robot, human, object
    pub subject: rosidl_runtime_rs::String,

    /// text, pose
    pub type_: rosidl_runtime_rs::String,

    /// data
    pub content: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::rmw::Pose,

}



impl Default for Info {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__msg__Info__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__msg__Info__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Info {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Info__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Info__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Info__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Info {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Info where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/msg/Info";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Info() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Request() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__msg__Request__init(msg: *mut Request) -> bool;
    fn communication_msgs__msg__Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Request>, size: usize) -> bool;
    fn communication_msgs__msg__Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Request>);
    fn communication_msgs__msg__Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Request>) -> bool;
}

// Corresponds to communication_msgs__msg__Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,

    /// all, robot_name
    pub to: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub action_name: rosidl_runtime_rs::String,

}



impl Default for Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__msg__Request__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__msg__Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Request where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/msg/Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Request() }
  }
}


#[link(name = "communication_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Introduction() -> *const std::ffi::c_void;
}

#[link(name = "communication_msgs__rosidl_generator_c")]
extern "C" {
    fn communication_msgs__msg__Introduction__init(msg: *mut Introduction) -> bool;
    fn communication_msgs__msg__Introduction__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Introduction>, size: usize) -> bool;
    fn communication_msgs__msg__Introduction__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Introduction>);
    fn communication_msgs__msg__Introduction__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Introduction>, out_seq: *mut rosidl_runtime_rs::Sequence<Introduction>) -> bool;
}

// Corresponds to communication_msgs__msg__Introduction
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Message sent to all robots

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Introduction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub available_actions: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub frame_id: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::rmw::Pose,

}



impl Default for Introduction {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !communication_msgs__msg__Introduction__init(&mut msg as *mut _) {
        panic!("Call to communication_msgs__msg__Introduction__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Introduction {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Introduction__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Introduction__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { communication_msgs__msg__Introduction__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Introduction {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Introduction where Self: Sized {
  const TYPE_NAME: &'static str = "communication_msgs/msg/Introduction";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__communication_msgs__msg__Introduction() }
  }
}


