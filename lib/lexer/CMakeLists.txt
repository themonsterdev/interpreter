add_library(Lexer STATIC
    # Lexeme
    include/Lexeme.h
    src/Lexeme.cpp
    # Lexer
    include/Lexer.h
    src/Lexer.cpp
)

target_include_directories(Lexer
    PUBLIC include/
)
