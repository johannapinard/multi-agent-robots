FROM ros:jazzy

ENV DEBIAN_FRONTEND=noninteractive
ENV ROS_DISTRO=jazzy
ENV WORKSPACE=/multi_agents_ws
ENV LANG=C.UTF-8
ENV LC_ALL=C.UTF-8

# ---------------------------------------------------------------------------
# Install dependencies for base-layer nodes (teleop, joy, QT serial, etc.)
# ---------------------------------------------------------------------------
RUN apt-get update && apt-get install -y --no-install-recommends \
    ros-${ROS_DISTRO}-moveit \
    ros-${ROS_DISTRO}-xacro \
    ros-${ROS_DISTRO}-tf2-ros \
    git \
    cmake \
    build-essential \
    qtbase5-dev \
    qt5-qmake \
    libqt5serialport5-dev \
    nano \
    libtinfo6 \
    python3-numpy \
    python3-scipy \
 && rm -rf /var/lib/apt/lists/*

# ---------------------------------------------------------------------------
# Create workspace
# Structure: /robot_ws/src/...
# ---------------------------------------------------------------------------
RUN mkdir -p ${WORKSPACE}/src
WORKDIR ${WORKSPACE}

# ---------------------------------------------------------------------------
# Copy your Wave-Rover Controller packages (as provided)
# ---------------------------------------------------------------------------
# If your project is organized like:
# project_root/docker/base/robot_ws/src/<packages>
COPY ./robot_ws/src/ ${WORKSPACE}/src/

# IF your existing files are flat (your original Dockerfile):
# COPY ./src ./ros2-wave-rover/src
# Adjust paths based on your source layout

# ---------------------------------------------------------------------------
# Environment setup
# ---------------------------------------------------------------------------


# Ensures container loads ROS workspace overlays at startup
RUN echo "source /opt/ros/jazzy/setup.bash" >> /root/.bashrc && \
    echo "source /robot_ws/install/setup.bash" >> /root/.bashrc


# ---------------------------------------------------------------------------
# Build workspace
# ---------------------------------------------------------------------------
RUN . /opt/ros/jazzy/setup.sh && \
    colcon build --symlink-install
    

# ---------------------------------------------------------------------------
# Copy entrypoint
# ---------------------------------------------------------------------------
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
#CMD ["bash"]