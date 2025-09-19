cmake_minimum_required(VERSION 3.30.5)

project(fixed-point VERSION 0.1.0 LANGUAGES CXX)

# generate compile_commands.json for IDE integration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# tests
include(CTest)
enable_testing()
add_subdirectory(tests)
