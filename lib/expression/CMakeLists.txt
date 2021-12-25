set(SOURCE_LIST
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
    include/Operator/AdditionExpression.h
    src/Operator/AdditionExpression.cpp
    # SubtractionExpression
    include/Operator/SubtractionExpression.h
    src/Operator/SubtractionExpression.cpp
    # MultiplicationExpression
    include/Operator/MultiplicationExpression.h
    src/Operator/MultiplicationExpression.cpp
    # DivisionExpression
    include/Operator/DivisionExpression.h
    src/Operator/DivisionExpression.cpp
    # ModuloExpression
    include/Operator/ModuloExpression.h
    src/Operator/ModuloExpression.cpp

    # Identifier
    include/Terminal/Identifier.h
    src/Terminal/Identifier.cpp
    # Number
    include/Terminal/Number.h
    src/Terminal/Number.cpp
)

add_library(Expression STATIC ${SOURCE_LIST})

target_include_directories(Expression
    PUBLIC include/
    PUBLIC lib/Context/include/
    PUBLIC lib/Tokenizer/include/
)

target_link_libraries(Expression
    Context
    Tokenizer
)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})
