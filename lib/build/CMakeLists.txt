add_subdirectory("../context/build"     "Context")
add_subdirectory("../expression/build"  "Expression")
add_subdirectory("../statement/build"   "Statement")

add_subdirectory("../tokenizer/build" "Tokenizer")
add_subdirectory("../lexer/build"     "Lexer")
add_subdirectory("../parser/build"    "Parser")

set_property(TARGET Context PROPERTY FOLDER "Libraries")
set_property(TARGET Expression PROPERTY FOLDER "Libraries")
set_property(TARGET Statement PROPERTY FOLDER "Libraries")

set_property(TARGET Tokenizer PROPERTY FOLDER "Libraries/Analyzer")
set_property(TARGET Lexer PROPERTY FOLDER "Libraries/Analyzer")
set_property(TARGET Parser PROPERTY FOLDER "Libraries/Analyzer")
