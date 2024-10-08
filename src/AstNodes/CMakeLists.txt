# src/AstNodes/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Add a library for AstNodes
add_library(AstNodes
    Program.cpp
    Block.cpp
    DataType.cpp
    TypeError.cpp
    FreePtr.cpp
    BinaryExp/BinaryExp.cpp
    BinaryExp/PlusExp.cpp
    BinaryExp/MinusExp.cpp
    BinaryExp/MultExp.cpp
    BinaryExp/DivExp.cpp
    BinaryExp/AndExp.cpp
    BinaryExp/OrExp.cpp
    BinaryExp/EQEQExp.cpp
    BinaryExp/GTExp.cpp
    BinaryExp/GTEQExp.cpp
    BinaryExp/LTExp.cpp
    BinaryExp/LTEQExp.cpp
    UnaryExp/UnaryExp.cpp
    UnaryExp/NegExp.cpp
    UnaryExp/NotExp.cpp
    FunctionExp/PrintExp.cpp
    FunctionExp/LambdaExp.cpp
    FunctionExp/FunctionCallExp.cpp
    Lit/NumLit.cpp
    Lit/VarLit.cpp
    Lit/StringLit.cpp
    Lit/BoolLit.cpp
    Lit/ArrayLit.cpp
    Statement/Assignment.cpp
    Statement/While.cpp
    Statement/Return.cpp
    Statement/For.cpp
    Statement/If.cpp
)

# Include directories for AstNodes
target_include_directories(AstNodes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})