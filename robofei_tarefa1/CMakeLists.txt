cmake_minimum_required(VERSION 3.8)
project(robofei_tarefa1)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Encontra os pacotes necessários
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Adiciona o executável do publisher
add_executable(publicarsobrerobo src/publicarsobrerobo.cpp)
ament_target_dependencies(publicarsobrerobo rclcpp std_msgs)

# Adiciona o executável do subscriber
add_executable(recebendorobo src/recebendorobo.cpp)
ament_target_dependencies(recebendorobo rclcpp std_msgs)


install(TARGETS
  publicarsobrerobo
  recebendorobo
  DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
