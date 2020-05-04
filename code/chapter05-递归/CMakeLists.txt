# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(chapter05 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# add_executable(print_test print_test.cpp)
# add_executable(polynomial polynomial.cpp)

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/exercise1")

add_executable(test_exercise1 exp5-1.cpp)
add_executable(test_example5-2 example5-2.cpp)
add_executable(test_example5-3 example5-3.cpp)
add_executable(test_example5-4 example5-4.cpp)

# 添加子目录
add_subdirectory(exercise1)

# 添加库
target_link_libraries(test_exercise1 exercise1)
target_link_libraries(test_example5-3 exercise1)
target_link_libraries(test_example5-4 exercise1)