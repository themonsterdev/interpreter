set(SOURCE_LIST 
    # TokenizerInterface
    "../include/Interface/TokenizerInterface.h"

    # AbstractTokenizer
    "../include/AbstractTokenizer.h"
    "../src/AbstractTokenizer.cpp"
    
    # StreamTokenizer
    "../include/StreamTokenizer.h"
    "../src/StreamTokenizer.cpp"

    # StringTokenizer
    "../include/StringTokenizer.h"
    "../src/StringTokenizer.cpp"

    # Token
    "../include/Token.h"
    "../src/Token.cpp"
)

add_library(Tokenizer STATIC ${SOURCE_LIST})

target_include_directories(Tokenizer
    PUBLIC "../include/"
)

# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/../" FILES ${SOURCE_LIST})
