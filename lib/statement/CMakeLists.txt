add_library(Statement STATIC
    include/Statement.h
    src/Statement.cpp
)

target_include_directories(Statement
    PUBLIC include/
    PUBLIC lib/Context/include/
    PUBLIC lib/Expression/include/
    PUBLIC lib/Tokenizer/include/
)

target_link_libraries(Statement
    Context
    Expression
    Tokenizer
)
