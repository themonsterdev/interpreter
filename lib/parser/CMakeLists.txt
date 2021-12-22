add_library(parser STATIC
    include/parser.h
    src/parser.cpp
)

target_include_directories(parser
    PUBLIC include/
    PUBLIC lib/tokenizer/include/
)

target_link_libraries(parser
    tokenizer
)
