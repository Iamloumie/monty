#include "monty.h"

/**
 * err - Prints appropiate error messages determined by their error code.
 * @code_err: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void err(int code_err, ...)
{
	va_list ag;
	char *operation;
	int num;

	va_start(ag, code_err);
	switch (code_err)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			num = va_arg(ag, int);
			operation = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, operation);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * other_errs - handles errors.
 * @code_err: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void other_errs(int code_err, ...)
{
	va_list ag;
	char *operation;
	int num;

	va_start(ag, code_err);
	switch (code_err)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			num = va_arg(ag, unsigned int);
			operation = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @code_err: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_err(int code_err, ...)
{
	va_list ag;
	int num;

	va_start(ag, code_err);
	num = va_arg(ag, int);
	switch (code_err)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	nodes_free();
	exit(EXIT_FAILURE);
}
