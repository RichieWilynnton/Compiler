cmake_minimum_required(VERSION 3.10)

# Set the project name
project(compiler)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectory for AstNodes
add_subdirectory(src/AstNodes)

# Add the executable
add_executable(compiler
    src/main.cpp
    src/Keywords.cpp
    src/Lexer.cpp
    src/Parser.cpp
    src/Testing.cpp
    src/Generator.cpp
    src/Scope.cpp
    src/Utils/TokenUtils.cpp
)

# Include directories
target_include_directories(compiler PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/Utils
)

# Link the AstNodes library
target_link_libraries(compiler PUBLIC AstNodes)

add_custom_command(TARGET compiler
    POST_BUILD
    COMMAND compiler
    COMMENT "Running MyCompiler executable"
)

add_custom_target(run
    COMMAND compiler
    DEPENDS compiler
    COMMENT "Build and run MyCompiler"
)
    