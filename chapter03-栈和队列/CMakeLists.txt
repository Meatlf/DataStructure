# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(chapter03 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# add_executable(print_test print_test.cpp)
# add_executable(polynomial polynomial.cpp)

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/exercise1")

add_executable(test_exercise1 exp3-1.cpp)
add_executable(test_exercise2 exp3-2.cpp)
add_executable(test_example3-4 example3-4.cpp)
add_executable(test_example3-5 example3-5.cpp)
# add_executable(test_example2-6 example2-6.cpp)

# 添加子目录
add_subdirectory(exercise1)

# 添加库
target_link_libraries(test_exercise1 exercise1)
target_link_libraries(test_exercise2 exercise1)
target_link_libraries(test_example3-4 exercise1)
target_link_libraries(test_example3-5 exercise1)
# target_link_libraries(test_example2-6 exercise1)