cmake_minimum_required(VERSION 3.22.1)  # CMake version check
project(interpreter)                    # Create project 'interpreter'

find_package(Doxygen
    REQUIRED dot
    OPTIONAL_COMPONENTS mscgen dia
)

if (DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_HTML_OUTPUT "docs")

    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/DOCS.md")

    set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}")
    set(DOXYGEN_PROJECT_NAME "Interprèteur")
    set(DOXYGEN_PROJECT_BRIEF "Construire avec c++")
    set(DOXYGEN_PROJECT_NUMBER "1.0.0")
    set(DOXYGEN_OUTPUT_LANGUAGE "French")

    set(DOXYGEN_FILES
        ${PROJECT_SOURCE_DIR}/DOCS.md
        lib/context/include
        lib/expression/include
        lib/parser/include
        lib/statement/include
        lib/tokenizer/include
    )

    doxygen_add_docs(
        doxygen             # target    
        ${DOXYGEN_FILES}    # directory
        COMMENT "Generate lib doc pages"
    )
endif()

set(CMAKE_CXX_STANDARD "20")              # Enable c++20 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /utf-8")

add_subdirectory(lib)
add_subdirectory(src)
