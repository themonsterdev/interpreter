cmake_minimum_required(VERSION 3.21.1)  # CMake version check
project(interpreter)                    # Create project 'interpreter'

set(CMAKE_CXX_STANDARD 14)              # Enable c++17 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")

include(lib/tokenizer/CMakeLists.txt)

add_executable(interpreter 
    src/main.cpp
)

target_include_directories(interpreter
    PUBLIC lib/tokenizer/include/
)
target_link_libraries(interpreter
    tokenizer
)
