add_library(tokenizer STATIC
    lib/tokenizer/src/token.cpp
    lib/tokenizer/src/tokenizer.cpp
)

target_include_directories(tokenizer
    PUBLIC lib/tokenizer/include/
)
