#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temp_store;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp_store = *stack;
	while (temp_store != NULL)
	{
		ascii = temp_store->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temp_store = temp_store->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp_store;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp_store = *stack;
	while (temp_store->next != NULL)
		temp_store = temp_store->next;

	temp_store->next = *stack;
	(*stack)->prev = temp_store;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp_store;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp_store = *stack;

	while (temp_store->next != NULL)
		temp_store = temp_store->next;

	temp_store->next = *stack;
	temp_store->prev->next = NULL;
	temp_store->prev = NULL;
	(*stack)->prev = temp_store;
	(*stack) = temp_store;
}
