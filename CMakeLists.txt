cmake_minimum_required(VERSION 3.10)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# used internally by CMake to identify your project
project(matrixCalc)

# Include the directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the main executable
add_executable(matrixCalc src/main.cpp src/matrix.cpp "include/matrix.h")

add_executable(my_test src/matrix.cpp src/main.cpp test/test.cpp "include/matrix.h")
target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

enable_testing()