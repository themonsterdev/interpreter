configure_file("../include/Prepropessor.h.in" "${PROJECT_BINARY_DIR}/include/Preprocessor.h")

set(CLIENT_FILES
    # Client
    "../include/Client.h"
    "../src/Client.cpp"

    # Entry point
    "../src/main.cpp"
    
    "../include/Prepropessor.h.in"
    "${PROJECT_BINARY_DIR}/include/Preprocessor.h"
)

add_executable(Client ${CLIENT_FILES})

target_include_directories(Client
    PUBLIC "../include/"
    PUBLIC "${PROJECT_BINARY_DIR}/include/"

    PUBLIC "../../Tokenizer/include/"
    PUBLIC "../../Parser/include/"
)

target_link_libraries(Client Tokenizer Parser)
