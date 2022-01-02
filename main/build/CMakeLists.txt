configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Prepropessor.h.in" "${CMAKE_CURRENT_SOURCE_DIR}/../include/Preprocessor.h")

set(CLIENT_FILES
    # Client
    "../include/Client.h"
    "../src/Client.cpp"

    # Context
    "../include/Context.h"
    "../src/Context.cpp"

    # Entry point
    "../src/main.cpp"
)

set(PARSER_FILES
     # Parser
     "../include/Parser/Parser.h"
     "../src/Parser/Parser.cpp"

    # ExpressionInterface
    "../include/Parser/Expression/Interface/ExpressionInterface.h"

    # AbstractExpression
    "../include/Parser/Expression/AbstractExpression.h"
    "../src/Parser/Expression/AbstractExpression.cpp"

    # StatementInterface
    "../include/Parser/Statement/Interface/StatementInterface.h"

    # AbstractStatement
    "../include/Parser/Statement/AbstractStatement.h"
    "../src/Parser/Statement/AbstractStatement.cpp"

    # PrintingStatement
    "../include/Parser/Statement/PrintingStatement.h"
    "../src/Parser/Statement/PrintingStatement.cpp"

    # VariableStatement
    "../include/Parser/Statement/VariableStatement.h"
    "../src/Parser/Statement/VariableStatement.cpp"

    # OperatorExpression
    "../include/Parser/Expression/Operator/OperatorExpression.h"
    "../src/Parser/Expression/Operator/OperatorExpression.cpp"

    # AdditionExpression
    "../include/Parser/Expression/Operator/Arithmetic/AdditionExpression.h"
    "../src/Parser/Expression/Operator/Arithmetic/AdditionExpression.cpp"

    # DivisionExpression
    "../include/Parser/Expression/Operator/Arithmetic/DivisionExpression.h"
    "../src/Parser/Expression/Operator/Arithmetic/DivisionExpression.cpp"

    # ModuloExpression
    "../include/Parser/Expression/Operator/Arithmetic/ModuloExpression.h"
    "../src/Parser/Expression/Operator/Arithmetic/ModuloExpression.cpp"

    # MultiplicationExpression
    "../include/Parser/Expression/Operator/Arithmetic/MultiplicationExpression.h"
    "../src/Parser/Expression/Operator/Arithmetic/MultiplicationExpression.cpp"

    # SubtractionExpression
    "../include/Parser/Expression/Operator/Arithmetic/SubtractionExpression.h"
    "../src/Parser/Expression/Operator/Arithmetic/SubtractionExpression.cpp"

    # NumberExpression
    "../include/Parser/Expression/NumberExpression.h"
    "../src/Parser/Expression/NumberExpression.cpp"

    # IdentifierExpression
    "../include/Parser/Expression/IdentifierExpression.h"
    "../src/Parser/Expression/IdentifierExpression.cpp"
)

set(TOKENIZER_FILES 
    # TokenizerInterface
    "../include/Tokenizer/Interface/TokenizerInterface.h"

    # AbstractTokenizer
    "../include/Tokenizer/AbstractTokenizer.h"
    "../src/Tokenizer/AbstractTokenizer.cpp"
    
    # StreamTokenizer
    "../include/Tokenizer/StreamTokenizer.h"
    "../src/Tokenizer/StreamTokenizer.cpp"

    # StringTokenizer
    "../include/Tokenizer/StringTokenizer.h"
    "../src/Tokenizer/StringTokenizer.cpp"

    # Token
    "../include/Tokenizer/Token.h"
    "../src/Tokenizer/Token.cpp"
)

set(HEADER_STDAFX "../include/stdafx.h")
set(SOURCE_STDAFX "../src/stdafx.cpp")

set(INTERPRETER_FILES
    # stdafx
    ${HEADER_STDAFX}
    ${SOURCE_STDAFX}

    ${CLIENT_FILES}
    ${PARSER_FILES}
    ${TOKENIZER_FILES}
)

add_executable(Interpreter ${INTERPRETER_FILES})

target_include_directories(Interpreter
    PUBLIC "../include/"
)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../" FILES ${INTERPRETER_FILES})
