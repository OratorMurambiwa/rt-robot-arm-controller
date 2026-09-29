cmake_minimum_required(VERSION 3.20)
project(robot_arm_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Create the executable from our C++ source file
add_executable(robot_arm_control_node
  src/robot_arm_control_node.cpp
)

# Link the ROS 2 C++ library to our executable
target_link_libraries(robot_arm_control_node
  PRIVATE
  rclcpp::rclcpp
)

# Install the executable so `ros2 run` can find it
install(
  TARGETS robot_arm_control_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)

  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
