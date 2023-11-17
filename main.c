#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: args count
 * @argv: arguments list
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(argv[1]);
	free_linkedList();
	return (0);
}

/**
 * create_newNode - Creates a node and assign data.
 * @val: value.
 * Return: new node. Otherwise NULL.
 */
stack_t *create_newNode(int val)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		error_files(4);
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->n = val;
	return (newNode);
}

/**
 * free_linkedList - Frees nodes in the stack.
 */
void free_linkedList(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * add_NodeTo_queue - Add node to the queue.
 * @new_node: Pointer to the new node.
 * @line_num: line number of the opcode.
 */
void add_NodeTo_queue(stack_t **new_node, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}
