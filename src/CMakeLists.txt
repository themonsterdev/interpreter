add_executable(interpreter main.cpp)

target_include_directories(interpreter
    PUBLIC lib/parser/include/
    PUBLIC lib/statement/include/
    PUBLIC lib/tokenizer/include/
)

target_link_libraries(interpreter
    parser
    statement
    tokenizer
)
