add_library(Tokenizer STATIC
    # Token
    "../include/Token.h"
    "../src/Token.cpp"
    # Tokenizer
    "../include/Tokenizer.h"
    "../src/Tokenizer.cpp"
    # StreamTokenizer
    "../include/StreamTokenizer.h"
    "../src/StreamTokenizer.cpp"
    # StringTokenizer
    "../include/StringTokenizer.h"
    "../src/StringTokenizer.cpp"
)

target_include_directories(Tokenizer
    PUBLIC "../include/"
)
