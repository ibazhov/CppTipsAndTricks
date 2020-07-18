cmake_minimum_required(VERSION 3.3)
project(cpp_test_and_tricks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(BUILD_1 main)
set(SOURCE_FILES_1 ${PROJECT_SOURCE_DIR}/main)
add_executable(${BUILD_1} ${SOURCE_FILES_1})