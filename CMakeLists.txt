cmake_minimum_required(VERSION 3.10)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# used internally by CMake to identify your project
project(matrixCalc)

# Include the directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the main executable
add_executable(matrixCalc src/matrix.cpp src/main.cpp)

add_executable(my_test src/matrix.cpp test/test.cpp)
 
target_include_directories(my_test PRIVATE ${PROJECT_SOURCE_DIR}/include)

enable_testing()