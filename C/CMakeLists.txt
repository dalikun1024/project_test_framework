# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(c_unittest_framework_demo LANGUAGES C)

find_package(unity REQUIRED)
message(STATUS ${unity_LIBS})

# example library
add_library(sum_integers ${CMAKE_CURRENT_SOURCE_DIR}/sum_integers.c)

# main code
add_executable(sum_up ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
target_link_libraries(sum_up sum_integers)

# unity testing binary
add_executable(unity_test_1 ${CMAKE_CURRENT_SOURCE_DIR}/test_unity_1.c)
target_link_libraries(unity_test_1 sum_integers unity::framework)
add_executable(unity_test_2 ${CMAKE_CURRENT_SOURCE_DIR}/test_unity_2.c)
target_link_libraries(unity_test_2 sum_integers unity::framework)

# mqtt testing binary
add_executable(mqtt_test_1 ${CMAKE_CURRENT_SOURCE_DIR}/test_mqtt_1.c)
target_link_libraries(mqtt_test_1 sum_integers)
add_executable(mqtt_test_2 ${CMAKE_CURRENT_SOURCE_DIR}/test_mqtt_2.c)
target_link_libraries(mqtt_test_2 sum_integers)

# enable testing functionality
enable_testing()

# define test
add_test(
  NAME unity_test_1
  COMMAND $<TARGET_FILE:unity_test_1> --success
  )
add_test(
  NAME unity_test_2
  COMMAND $<TARGET_FILE:unity_test_2> --success
  )

add_test(
  NAME mqtt_test_1
  COMMAND $<TARGET_FILE:mqtt_test_1> --success
  )
add_test(
  NAME mqtt_test_2
  COMMAND $<TARGET_FILE:mqtt_test_2> --success
  )

set_tests_properties(
unity_test_1
unity_test_2
  PROPERTIES
  	LABELS "unity"
  )
set_tests_properties(
mqtt_test_1
mqtt_test_2
  PROPERTIES
  	LABELS "mqtt"
  )