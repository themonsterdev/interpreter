cmake_minimum_required(VERSION 3.22.1)  # CMake version check

project(interpreter)                    # Create project 'interpreter'

# check if Doxygen is installed
find_package(Doxygen
    REQUIRED dot
    OPTIONAL_COMPONENTS mscgen dia
)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN  "doxygen/config/Doxyfile")
    set(DOXYGEN_OUT "Doxyfile")

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( Doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        SOURCES
            "doxygen/config/Doxyfile"
            "doxygen/config/DoxygenLayout.xml"
            "doxygen/diagram/ebnf/ArithmeticOperatorExpression.png"
            "doxygen/diagram/ebnf/ComparisonOperatorExpression.png"
            "doxygen/diagram/ebnf/ExpressionList.png"
            "doxygen/diagram/ebnf/Identifier.png"
            "doxygen/diagram/ebnf/Number.png"
            "doxygen/diagram/ebnf/Statement.png"
            "doxygen/diagram/ast-diagram.png"
            "doxygen/diagram/interpreter-diagram.png"
            "doxygen/ebnf.md"
            "doxygen/index.md"
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
endif()

set(CMAKE_CXX_STANDARD "20")              # Enable c++20 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /utf-8")

add_subdirectory(lib)
add_subdirectory(src)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set_property(TARGET Doxygen PROPERTY FOLDER "Documentation")

set_property(TARGET Context PROPERTY FOLDER "Libraries")
set_property(TARGET Expression PROPERTY FOLDER "Libraries")
set_property(TARGET Statement PROPERTY FOLDER "Libraries")

set_property(TARGET Tokenizer PROPERTY FOLDER "Libraries/Analyzer")
set_property(TARGET Lexer PROPERTY FOLDER "Libraries/Analyzer")
set_property(TARGET Parser PROPERTY FOLDER "Libraries/Analyzer")

set_property(TARGET Interpreter PROPERTY FOLDER "Main")
