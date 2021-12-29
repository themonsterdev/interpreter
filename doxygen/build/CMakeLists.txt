# check if Doxygen is installed
find_package(Doxygen
    REQUIRED dot
    OPTIONAL_COMPONENTS mscgen dia
)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN  "../config/Doxyfile")
    set(DOXYGEN_OUT "Doxyfile")

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    set(SOURCE_LIST
        # Config Files
        "../config/Doxyfile"
        "../config/DoxygenLayout.xml"

        # Graph Files
        "../diagrams/dia/example.dia"
        "../diagrams/msc/example.msc"
        "../diagrams/dot/example.dot"

        # Image Files
        "../images/ebnf/ArithmeticOperatorExpression.png"
        "../images/ebnf/ComparisonOperatorExpression.png"
        "../images/ebnf/ExpressionList.png"
        "../images/ebnf/Identifier.png"
        "../images/ebnf/Number.png"
        "../images/ebnf/Statement.png"
        "../images/ast-diagram.png"
        "../images/interpreter-diagram.png"

        # Page
        "../pages/grammar-ebnf.md"
        "../pages/dessign-pattern/dessign-pattern.md"
        "../pages/dessign-pattern/interpreter.md"
        "../pages/doxygen.md"
        "../pages/index.md"

        # Project README
        "../../../README.md"
    )

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( Doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        SOURCES ${SOURCE_LIST}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()
