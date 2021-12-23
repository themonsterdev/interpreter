add_library(Statement STATIC
    # Statement
    include/Statement.h
    src/Statement.cpp
    # AssignmentStatement
    include/AssignmentStatement.h
    src/AssignmentStatement.cpp
    # PrintStatement
    include/PrintStatement.h
    src/PrintStatement.cpp
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
