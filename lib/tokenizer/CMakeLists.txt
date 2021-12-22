add_library(tokenizer STATIC
    include/token.h
    src/token.cpp
    include/tokenizer.h
    src/tokenizer.cpp
)

target_include_directories(tokenizer
    PUBLIC include/
)
