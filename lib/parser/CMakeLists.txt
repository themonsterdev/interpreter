add_library(Parser STATIC
    include/Parser.h
    src/Parser.cpp
)

target_include_directories(Parser
    PUBLIC include/
    PUBLIC lib/Tokenizer/include/
)

target_link_libraries(Parser
    Tokenizer
)
