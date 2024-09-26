# Monty Bytecode Interpreter

This project implements an interpreter for Monty ByteCodes files. Monty is a simple programming language that relies on a unique stack data structure with specific instructions to manipulate it.

## Files in the Project

- `error_handler.c`: Handles error messages and error reporting.
- `files_on_bf`: (Purpose unclear, possibly related to brainfuck or bytecode files)
- `function_stacks1.c`: Contains implementations of stack operations.
- `function_stacks2.c`: Additional stack operation implementations.
- `main.c`: The main entry point of the program.
- `monty`: The compiled executable of the Monty interpreter.
- `monty.h`: Header file containing function prototypes and structure definitions.
- `stack_operation.c`: Implements core stack operations.
- `stack_strings.c`: Handles string-related stack operations.
- `test.m`: A test file containing Monty bytecode instructions.
- `tools.c`: Utility functions used throughout the project.

## Compilation

To compile the Monty interpreter, use the following command:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Usage

```
./monty file
```

Where `file` is the path to the file containing Monty byte code.

## Monty Byte Code Files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

## Example

```
$ cat test.m
push 1
push 2
push 3
pall
$ ./monty test.m
3
2
1
```
