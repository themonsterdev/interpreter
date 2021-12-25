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
    include/Operator/Arithmetic/AdditionExpression.h
    src/Operator/Arithmetic/AdditionExpression.cpp
    # SubtractionExpression
    include/Operator/Arithmetic/SubtractionExpression.h
    src/Operator/Arithmetic/SubtractionExpression.cpp
    # MultiplicationExpression
    include/Operator/Arithmetic/MultiplicationExpression.h
    src/Operator/Arithmetic/MultiplicationExpression.cpp
    # DivisionExpression
    include/Operator/Arithmetic/DivisionExpression.h
    src/Operator/Arithmetic/DivisionExpression.cpp
    # ModuloExpression
    include/Operator/Arithmetic/ModuloExpression.h
    src/Operator/Arithmetic/ModuloExpression.cpp

    # EqualToExpression
    include/Operator/Comparison/EqualToExpression.h
    src/Operator/Comparison/EqualToExpression.cpp
    # GreaterThanExpression
    include/Operator/Comparison/GreaterThanExpression.h
    src/Operator/Comparison/GreaterThanExpression.cpp
    # GreaterThanOrEqualToExpression
    include/Operator/Comparison/GreaterThanOrEqualToExpression.h
    src/Operator/Comparison/GreaterThanOrEqualToExpression.cpp
    # LessThanExpression
    include/Operator/Comparison/LessThanExpression.h
    src/Operator/Comparison/LessThanExpression.cpp
    # LessThanOrEqualToExpression
    include/Operator/Comparison/LessThanOrEqualToExpression.h
    src/Operator/Comparison/LessThanOrEqualToExpression.cpp
    # NotEqualToExpression
    include/Operator/Comparison/NotEqualToExpression.h
    src/Operator/Comparison/NotEqualToExpression.cpp
    # ThreeWayExpression
    include/Operator/Comparison/ThreeWayExpression.h
    src/Operator/Comparison/ThreeWayExpression.cpp

    # NegationExpression
    include/Operator/Logical/NegationExpression.h
    src/Operator/Logical/NegationExpression.cpp
    # AndExpression
    include/Operator/Logical/AndExpression.h
    src/Operator/Logical/AndExpression.cpp
    # OrExpression
    include/Operator/Logical/OrExpression.h
    src/Operator/Logical/OrExpression.cpp

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
