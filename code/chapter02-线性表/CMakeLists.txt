# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(chapter01 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/exercise1")

add_executable(test_exercise1 exp2-1.cpp)
add_executable(test_exercise2 exp2-2.cpp)
add_executable(test_exercise3 exp2-3.cpp)
add_executable(test_example2-3 example2-3.cpp)
add_executable(test_example2-4 example2-4.cpp)
add_executable(test_example2-6 example2-6.cpp)
add_executable(test_example2-9 example2-9.cpp)

# 添加子目录
add_subdirectory(exercise1)

# 添加库
target_link_libraries(test_exercise1 exercise1)
target_link_libraries(test_exercise2 exercise1)
target_link_libraries(test_exercise3 exercise1)
target_link_libraries(test_example2-3 exercise1)
target_link_libraries(test_example2-4 exercise1)
target_link_libraries(test_example2-6 exercise1)
target_link_libraries(test_example2-9 exercise1)