cmake_minimum_required(VERSION 2.8.3)
project(esim_visualization)

find_package(catkin_simple REQUIRED)
catkin_simple()

# This macro ensures modules and global scripts declared therein get installed
# See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
catkin_python_setup()

set(HEADERS
    include/esim/visualization/publisher_interface.hpp
    include/esim/visualization/ros_utils.hpp
    include/esim/visualization/ros_publisher.hpp
    include/esim/visualization/rosbag_writer.hpp
    include/esim/visualization/adaptive_sampling_benchmark_publisher.hpp
    include/esim/visualization/synthetic_optic_flow_publisher.hpp
    include/esim/visualization/text_file_publisher.hpp
)

set(SOURCES
    src/ros_utils.cpp
    src/ros_publisher.cpp
    src/rosbag_writer.cpp
    src/adaptive_sampling_benchmark_publisher.cpp
    src/synthetic_optic_flow_publisher.cpp
    src/text_file_publisher.cpp
)

cs_add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

cs_install()
cs_export()
