# src/AstNodes/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Add a library for AstNodes
add_library(AstNodes
    Program.cpp
    DataType.cpp
    TypeError.cpp
    BinaryExp/BinaryExp.cpp
    BinaryExp/PlusExp.cpp
    BinaryExp/MinusExp.cpp
    BinaryExp/MultExp.cpp
    BinaryExp/DivExp.cpp
    UnaryExp/UnaryExp.cpp
    UnaryExp/NegExp.cpp
    Lit/NumLit.cpp
    Lit/VarLit.cpp
    Statement/Assignment.cpp
)

# Include directories for AstNodes
target_include_directories(AstNodes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})