add_executable(Interpreter main.cpp)

target_include_directories(Interpreter
    PUBLIC lib/Parser/include/
    PUBLIC lib/Statement/include/
    PUBLIC lib/Tokenizer/include/
)

target_link_libraries(Interpreter
    Parser
    Statement
    Tokenizer
)
