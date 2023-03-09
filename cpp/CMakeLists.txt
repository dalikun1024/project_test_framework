# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(cpp_unittest_framework_demo LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#google test
find_package(GTest CONFIG REQUIRED)

# example library
add_library(sum_integers ${CMAKE_CURRENT_SOURCE_DIR}/sum_integers.cpp)

# main code
add_executable(sum_up ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(sum_up sum_integers)

# catch testing binary
add_executable(catch_test_1 ${CMAKE_CURRENT_SOURCE_DIR}/test_catch_1.cpp)
target_link_libraries(catch_test_1 sum_integers)
add_executable(catch_test_2 ${CMAKE_CURRENT_SOURCE_DIR}/test_catch_2.cpp)
target_link_libraries(catch_test_2 sum_integers)

# doctest testing binary
add_executable(doctest_1 ${CMAKE_CURRENT_SOURCE_DIR}/test_doctest_1.cpp)
target_link_libraries(doctest_1 sum_integers)
add_executable(doctest_2 ${CMAKE_CURRENT_SOURCE_DIR}/test_doctest_2.cpp)
target_link_libraries(doctest_2 sum_integers)

# gtest testing binary
add_executable(gtest_1 ${CMAKE_CURRENT_SOURCE_DIR}/test_gtest_1.cpp)
target_link_libraries(gtest_1 sum_integers GTest::gtest_main)
add_executable(gtest_2 ${CMAKE_CURRENT_SOURCE_DIR}/test_gtest_2.cpp)
target_link_libraries(gtest_2 sum_integers GTest::gtest_main)

# enable testing functionality
enable_testing()

# define test
add_test(
  NAME catch_test_1
  COMMAND $<TARGET_FILE:catch_test_1> --success
  )
add_test(
  NAME catch_test_2
  COMMAND $<TARGET_FILE:catch_test_2> --success
  )

add_test(
  NAME doctest_1
  COMMAND $<TARGET_FILE:doctest_1> --success
  )
add_test(
  NAME doctest_2
  COMMAND $<TARGET_FILE:doctest_2> --success
  )

add_test(
  NAME gtest_1
  COMMAND $<TARGET_FILE:gtest_1> --success
  )
add_test(
  NAME gtest_2
  COMMAND $<TARGET_FILE:gtest_2> --success
  )


set_tests_properties(
  catch_test_1
  catch_test_2
  PROPERTIES
  	LABELS "catch"
  )
set_tests_properties(
  doctest_1
  doctest_2
  PROPERTIES
  	LABELS "doctest"
  )

  set_tests_properties(
    gtest_1
    gtest_2
    PROPERTIES
      LABELS "gtest"
    )