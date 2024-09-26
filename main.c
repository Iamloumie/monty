#include "monty.h"
stack_t *node_head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	nodes_free();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * nodes_free - Frees nodes in the stack.
 */
void nodes_free(void)
{
	stack_t *temp_store;

	if (node_head == NULL)
		return;

	while (node_head != NULL)
	{
		temp_store = node_head;
		node_head = node_head->next;
		free(temp_store);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (temp_store->next != NULL)
		temp_store = temp_store->next;

	temp_store->next = *new_node;
	(*new_node)->prev = temp_store;

}
