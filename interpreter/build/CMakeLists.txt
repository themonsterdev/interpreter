configure_file("../include/Prepropessor.h.in" "${PROJECT_BINARY_DIR}/include/Preprocessor.h")

set(SOURCE_FILES
    # Interpreter
    "../include/Interpreter.h"
    "../src/Interpreter.cpp"

    "../src/main.cpp"
    
    "../include/Prepropessor.h.in"
    "${PROJECT_BINARY_DIR}/include/Preprocessor.h"
)

add_executable(Interpreter ${SOURCE_FILES})

target_include_directories(Interpreter
    PUBLIC "../include/"
    PUBLIC "${PROJECT_BINARY_DIR}/include/"
    PUBLIC "lib/Parser/include/"
    PUBLIC "lib/Statement/include/"
    PUBLIC "lib/Tokenizer/include/"
)

target_link_libraries(Interpreter
    Parser
    Statement
    Tokenizer
)

set_property(TARGET Interpreter PROPERTY FOLDER "Main")
