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
        # Graph Files
        "../dia/example.dia"
        "../msc/example.msc"
        "../dot/example.dot"
        # Config Files
        "../config/Doxyfile"
        "../config/DoxygenLayout.xml"
        # Image Files
        "../diagram/ebnf/ArithmeticOperatorExpression.png"
        "../diagram/ebnf/ComparisonOperatorExpression.png"
        "../diagram/ebnf/ExpressionList.png"
        "../diagram/ebnf/Identifier.png"
        "../diagram/ebnf/Number.png"
        "../diagram/ebnf/Statement.png"
        "../diagram/ast-diagram.png"
        "../diagram/interpreter-diagram.png"
        # Page Readme
        "../grammar-ebnf.md"
        "../dessign-pattern/index.md"
        "../dessign-pattern/interpreter.md"
        "../doxygen.md"
        "../index.md"
        # Project README
        "../../README.md"
    )

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( Doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        SOURCES ${SOURCE_LIST}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )

    set_property(TARGET Doxygen PROPERTY FOLDER "Documentation")
endif()
