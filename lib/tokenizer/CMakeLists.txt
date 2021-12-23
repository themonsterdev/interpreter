add_library(Tokenizer STATIC
    include/Token.h
    src/Token.cpp
    include/Tokenizer.h
    src/Tokenizer.cpp
)

target_include_directories(Tokenizer
    PUBLIC include/
)
