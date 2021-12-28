cmake_minimum_required(VERSION 3.22.1)  # CMake version check
project(Interpreter VERSION 2.0.0)		# Create project 'interpreter'

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD	"20")            # Enable c++20 standard
set(CMAKE_CXX_FLAGS		"${CMAKE_CXX_FLAGS} /W4 /utf-8")

add_subdirectory("../doxygen/build"     "Doxygen")
add_subdirectory("../lib/build"         "Libraries")
add_subdirectory("../interpreter/build" "Interpreter")
