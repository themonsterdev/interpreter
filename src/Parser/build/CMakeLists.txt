set(SOURCE_LIST
    # Parser
    "../include/Parser.h"
    "../src/Parser.cpp"

    # StatementInterface
    "../include/Interface/StatementInterface.h"

    # PrintingStatement
    "../include/PrintingStatement.h"
    "../src/PrintingStatement.cpp"

    # VariableStatement
    "../include/VariableStatement.h"
    "../src/VariableStatement.cpp"
)

add_library(Parser STATIC ${SOURCE_LIST})

target_include_directories(Parser
    PUBLIC "../include/"
    PUBLIC "../../Client/include/"
    PUBLIC "../../Tokenizer/include/"
)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../" FILES ${SOURCE_LIST})
