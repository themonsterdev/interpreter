add_library(context STATIC
    include/context.h
    src/context.cpp
)

target_include_directories(context
    PUBLIC include/
)
