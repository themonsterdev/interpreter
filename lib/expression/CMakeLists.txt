add_library(expression STATIC
    include/expression.h
    src/expression.cpp
)

target_include_directories(expression
    PUBLIC include/
    PUBLIC lib/tokenizer/include/
)

target_link_libraries(expression
    tokenizer
)
