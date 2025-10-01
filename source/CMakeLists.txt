cmake_minimum_required(VERSION 3.8)
project(source)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)


add_executable(publicar src/pub.cpp)
ament_target_dependencies(publicar rclcpp example_interfaces)
add_executable(sub_pub src/sub_pub.cpp)
ament_target_dependencies(sub_pub rclcpp example_interfaces)

install(TARGETS
  publicar
  sub_pub
  DESTINATION lib/${PROJECT_NAME})



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
