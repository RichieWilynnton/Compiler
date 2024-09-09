# MiniP

**MiniP** is a custom-built compiler written in C++ that translates code written in a custom programming language into C code. The compiler processes the source code in three primary steps: Tokenizing (Lexing), Parsing, and Code Generation. (Might need to implement another separate pass for further optimization)

This project is for learning purposes and aims to explore and understand the concepts of compiler & programming language design and optimization. I have previously implemented an **interpreter** in **Haskell**, a functional programming language and this is my first attempt in building a compiler written in an object-oriented fashion.

## Local Run
To run this project on Linux,

Run:
    ./compile.sh
    ./run.sh
    (Make sure permission is given to run these files, eg. run chmod +x compile.sh & chmod +x run.sh
## Features

- **Constant Folding Optimization**: Optimizes constant expressions at compile time.
- **Loop Unrolling Optimization** : Removing extra condition check after every iteration of a loop.
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
  <LambdaExp> := "lambda" (type exp1, type exp2) {...}
  
- **Type Declarations**

    num, bool, string, array (Type declarations are only required when getting inputs & defining function params)


### Example Code
- Type Errors - type checking is done in compile-time, along with the providance of appropriate error message.
```
------------Code------------
let a = a + 3
------------Output------------
Error at Position: 3 content: a
terminate called after throwing an instance of 'std::runtime_error'
  what():  Error during parsing: Undeclared variable
```

- Constant Folding - expressions are evaluated during compile-time whenever possible
```
------------Code------------
let a = 5
let b = 6
print(((a * b / 3 + 2 - (100 - a)) == 5) and (b >= a))
------------C Code------------
#include <stdio.h>
#include "functions.h"
#include "vector.h"
#include "print.h"
int main(){
int a = 5;
int b = 6;
print_bool(false); //constant folded
print_newline();
return 0;
}
------------Output------------
false
```
- Loop Unrolling - Loops that have a predictable, fixed range are unfolded during compilation, this removes the extra condition check that exists in a normal for loop after every iteration
```
------------Code------------
let a = 5
let b = 6
print(((a * b / 3 + 2 - (100 - a)) == 5) and (b >= a))
------------C Code------------
#include <stdio.h>
#include "functions.h"
#include "vector.h"
#include "print.h"
int main(){
int n = 5;
{
{
print_int(0);
print_newline();
};
{
print_int(1);
print_newline();
};
{
print_int(2);
print_newline();
};
{
print_int(3);
print_newline();
};
{
print_int(4);
print_newline();
};
};
;

return 0;
}

------------Output------------
0
1
2
3
4

```
- Lambda Expressions - Functions are treated as first class members, meaning it shares the same priveleges as other data types like numbers and strings. It can:
    - Retain the environment in which it was declared
    - Go in and out of scope
```
------------Code------------
let a = 40
let funcA = lambda (num y) => void {
    print(y)
}
let add = lambda (num x) => num {
    funcA(x)
    return (x+a)
}
print(add(4))
------------Output------------
4 
44
```

