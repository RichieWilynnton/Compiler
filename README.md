# MiniP

**MiniP** is a custom-built compiler written in C++ that translates code written in a custom programming language into C code. The compiler processes the source code in three primary steps: Tokenizing (Lexing), Parsing, and Code Generation. (Might need to implement another separate pass for further optimization)

This project is for learning purposes and aims to explore and understand the concepts of compiler & programming language design and optimization. I have previously implemented an interpreter in Haskell, a functional programming language and this is my first attempt in building a compiler written in an object-oriented fashion.

## Local Run
To run this project on Linux, navigate to the `{project_path}/api` directory and execute the following command:

    ./compiler code.txt

The output c file will reside in `{project_path}/api`. To execute the c file, simply run:

    make
    
## Features

- **Constant Folding Optimization**: Optimizes constant expressions at compile time.
- **Static Scoping**: Ensures that variable scope is determined during compilation.
- **Efficient Code Generation**: Translates high-level constructs into optimized C code.
- **Modular Architecture**: Separate passes for Lexing, Parsing, and Code Generation allow for easy modifications and extensions.
## Syntax

### Statements

- **Program**: A sequence of statements.
  ```plaintext
  Program := Statement[]
- **Assignment**: Assigns the result of an expression to a new variable
  ```plaintext
  Assignment := "let" Identifier "=" Expression
- **Modify**: Modifies the result of an existing variable
  ```plaintext
  Modify := "let" Identifier "=>" Expression
- **If Statement**
  ```plaintext
  IfStatement := "if" Expression {...}
- **While Statement**
  ```plaintext
  WhileStatement := "while" Expression {...}
- **For Statement** : 1 -> 3 means it will loop through 1, 2, 3
  ```plaintext
  ForStatement := "for" "let" Identifier "->" Expression "to" Expression {...}
  
### Expressions

- **Expression**
  ```plaintext
  <Expression> ::= <ComparisonExp>
- **Comparison Expression**
  ```plaintext
  <ComparisonExp> ::= <AdditiveExp> 
                | <ComparisonExp> ">" <AdditiveExp>
                | <ComparisonExp> ">=" <AdditiveExp>
                | <ComparisonExp> "<" <AdditiveExp>
                | <ComparisonExp> "<=" <AdditiveExp>
                | <ComparisonExp> "==" <AdditiveExp>
                | <ComparisonExp> "!=" <AdditiveExp>
  
- **Additive Expression**
  ```plaintext
  <AdditiveExp> ::= <MultiplicativeExp> 
                | <AdditiveExp> "+" <MultiplicativeExp>
                | <AdditiveExp> "-" <MultiplicativeExp>
                | <AdditiveExp> "and" <MultiplicativeExp>
                | <AdditiveExp> "or" <MultiplicativeExp>
- **Multiplicative Expression**
  ```plaintext
  <MultiplicativeExp> ::= <PrimaryExp>
                      | <MultiplicativeExp> "*" <PrimaryExp>
                      | <MultiplicativeExp> "/" <PrimaryExp>
- **Primary Expression**
  ```plaintext
  <PrimaryExp> ::= Literal
             | "(" Expression ")"
             | "-" PrimaryExp
             | "!" PrimaryExp
             | PrimaryExp[Expression]

- **Literals**
  ```plaintext
  <Literals> ::= NumLit
             | Identifier
             | BoolLit
             | StringLit
             | ArrayLit

  <NumLit> ::= `decimal number`
  <Identifier> ::= `variable name`
  <BoolLit> ::= true | false
  <StringLit> ::= "`group of characters`"
  <ArrayLit> ::= [Expression, Expression, ...]
  
