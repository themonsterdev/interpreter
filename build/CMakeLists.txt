cmake_minimum_required(VERSION 3.22.1)  # CMake version check
project(Interpreter VERSION 2.0.1)		# Create project 'interpreter'

set(CMAKE_CXX_STANDARD	            "20")            # Enable c++20 standard
# set(CMAKE_CXX_FLAGS		            "${CMAKE_CXX_FLAGS} /DDEBUG /W4 /utf-8")

add_subdirectory("../doxygen/build" "Documentation")
add_subdirectory("../main/build"    "Interpreter")
