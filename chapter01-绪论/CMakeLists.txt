# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(chapter01 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# add_executable(print_test print_test.cpp)
# add_executable(polynomial polynomial.cpp)

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/exercise1")

add_executable(project01 01-复杂度1-最大子列和问题.cpp)
add_executable(project02 01-复杂度2-MaximumSubsequenceSum.cpp)
add_executable(test_exercise1 exp2-1.cpp)

# 添加子目录
add_subdirectory(exercise1)

# 添加库
target_link_libraries(test_exercise1 exercise1)
