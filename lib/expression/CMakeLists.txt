add_library(Expression STATIC
    # Expression
    include/Expression.h
    src/Expression.cpp
    # TerminalExpression
    include/TerminalExpression.h
    src/TerminalExpression.cpp
    # NonTerminalExpression
    include/NonTerminalExpression.h
    src/NonTerminalExpression.cpp
    # AdditionExpression
    include/AdditionExpression.h
    src/AdditionExpression.cpp
    # SubtractionExpression
    include/SubtractionExpression.h
    src/SubtractionExpression.cpp
    # MultiplicationExpression
    include/MultiplicationExpression.h
    src/MultiplicationExpression.cpp
    # DivisionExpression
    include/DivisionExpression.h
    src/DivisionExpression.cpp
    # ModuloExpression
    include/ModuloExpression.h
    src/ModuloExpression.cpp
)

target_include_directories(Expression
    PUBLIC include/
    PUBLIC lib/Context/include/
    PUBLIC lib/Tokenizer/include/
)

target_link_libraries(Expression
    Context
    Tokenizer
)
