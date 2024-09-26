#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp_store;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (node_head == NULL)
	{
		node_head = *new_node;
		return;
	}
	temp_store = node_head;
	node_head = *new_node;
	node_head->next = temp_store;
	temp_store->prev = node_head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_store;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp_store = *stack;
	while (temp_store != NULL)
	{
		printf("%d\n", temp_store->n);
		temp_store = temp_store->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_store;

	if (stack == NULL || *stack == NULL)
		other_errs(7, line_number);

	temp_store = *stack;
	*stack = temp_store->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp_store);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		other_errs(6, line_number);
	printf("%d\n", (*stack)->n);
}
