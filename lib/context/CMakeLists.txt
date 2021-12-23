add_library(Context STATIC
    include/Context.h
    src/Context.cpp
)

target_include_directories(Context
    PUBLIC include/
)
