cmake_minimum_required(VERSION 3.12)
project(Homework6)

set(CMAKE_CXX_STANDARD 14)

# This uses class with composition
add_executable(homework6 wine_example.cpp Wine.cpp)

# This uses class with private inheritance
#add_executable(homework6 wine_example.cpp Wine_PI.cpp)
#add_compile_definitions(PRIVATE_INHERITANCE)
