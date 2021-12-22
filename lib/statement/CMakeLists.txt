add_library(statement STATIC
    include/statement.h
    src/statement.cpp
)

target_include_directories(statement
    PUBLIC include/
    PUBLIC lib/tokenizer/include/
)

target_link_libraries(statement
    tokenizer
)
