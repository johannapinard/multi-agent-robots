#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to communication_msgs__msg__Alert
/// Message sent to all robots

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Alert {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// 1: battery below 20%, 2: sensor not available
    pub code: i32,

}



impl Default for Alert {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Alert::default())
  }
}

impl rosidl_runtime_rs::Message for Alert {
  type RmwMsg = super::msg::rmw::Alert;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        code: msg.code,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      code: msg.code,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      code: msg.code,
    }
  }
}


// Corresponds to communication_msgs__msg__Answer

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Answer {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

    /// should be the same as request id
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub to: std::string::String,

    /// 0 error, 1 success, 2 ongoing
    pub response_code: i32,

    /// move, scan etc
    pub current_action: std::string::String,

    /// human-readable log message
    pub details: std::string::String,

}



impl Default for Answer {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Answer::default())
  }
}

impl rosidl_runtime_rs::Message for Answer {
  type RmwMsg = super::msg::rmw::Answer;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        id: msg.id,
        to: msg.to.as_str().into(),
        response_code: msg.response_code,
        current_action: msg.current_action.as_str().into(),
        details: msg.details.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      id: msg.id,
        to: msg.to.as_str().into(),
      response_code: msg.response_code,
        current_action: msg.current_action.as_str().into(),
        details: msg.details.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      id: msg.id,
      to: msg.to.to_string(),
      response_code: msg.response_code,
      current_action: msg.current_action.to_string(),
      details: msg.details.to_string(),
    }
  }
}


// Corresponds to communication_msgs__msg__Info
/// TODO custom description

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub header: std_msgs::msg::Header,

    /// robot, human, object
    pub subject: std::string::String,

    /// text, pose
    pub type_: std::string::String,

    /// data
    pub content: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::Pose,

}



impl Default for Info {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Info::default())
  }
}

impl rosidl_runtime_rs::Message for Info {
  type RmwMsg = super::msg::rmw::Info;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        subject: msg.subject.as_str().into(),
        type_: msg.type_.as_str().into(),
        content: msg.content.as_str().into(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        subject: msg.subject.as_str().into(),
        type_: msg.type_.as_str().into(),
        content: msg.content.as_str().into(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      subject: msg.subject.to_string(),
      type_: msg.type_.to_string(),
      content: msg.content.to_string(),
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
    }
  }
}


// Corresponds to communication_msgs__msg__Request

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,

    /// all, robot_name
    pub to: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub action_name: std::string::String,

}



impl Default for Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Request::default())
  }
}

impl rosidl_runtime_rs::Message for Request {
  type RmwMsg = super::msg::rmw::Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        id: msg.id,
        to: msg.to.as_str().into(),
        action_name: msg.action_name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      id: msg.id,
        to: msg.to.as_str().into(),
        action_name: msg.action_name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      id: msg.id,
      to: msg.to.to_string(),
      action_name: msg.action_name.to_string(),
    }
  }
}


// Corresponds to communication_msgs__msg__Introduction
/// Message sent to all robots

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Introduction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub name: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub available_actions: Vec<std::string::String>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub frame_id: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pose: geometry_msgs::msg::Pose,

}



impl Default for Introduction {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Introduction::default())
  }
}

impl rosidl_runtime_rs::Message for Introduction {
  type RmwMsg = super::msg::rmw::Introduction;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        available_actions: msg.available_actions
          .into_iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        frame_id: msg.frame_id.as_str().into(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.pose)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        name: msg.name.as_str().into(),
        available_actions: msg.available_actions
          .iter()
          .map(|elem| elem.as_str().into())
          .collect(),
        frame_id: msg.frame_id.as_str().into(),
        pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.pose)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      name: msg.name.to_string(),
      available_actions: msg.available_actions
          .into_iter()
          .map(|elem| elem.to_string())
          .collect(),
      frame_id: msg.frame_id.to_string(),
      pose: geometry_msgs::msg::Pose::from_rmw_message(msg.pose),
    }
  }
}


