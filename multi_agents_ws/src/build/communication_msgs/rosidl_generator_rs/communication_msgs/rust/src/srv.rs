#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to communication_msgs__srv__GetPose_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPose_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub item: std::string::String,

}



impl Default for GetPose_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPose_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GetPose_Request {
  type RmwMsg = super::srv::rmw::GetPose_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        item: msg.item.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        item: msg.item.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      item: msg.item.to_string(),
    }
  }
}


// Corresponds to communication_msgs__srv__GetPose_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GetPose_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub color: std::string::String,

}



impl Default for GetPose_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::GetPose_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GetPose_Response {
  type RmwMsg = super::srv::rmw::GetPose_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        color: msg.color.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        color: msg.color.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      color: msg.color.to_string(),
    }
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


