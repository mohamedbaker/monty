#include "monty.h"


/**
 * push - Adds a node to the stack.
 * @new_node: Pointer to  new node.
 * @line_num: line number of of the opcode.
 */
void push(stack_t **new_node, __attribute__((unused))unsigned int line_num)
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
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * pop - pops a node from the stack.
 * @top_node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void pop(stack_t **top_node, unsigned int line_number)
{
	stack_t *temp;

	if (top_node == NULL || *top_node == NULL)
		error_stack(7, line_number);

	temp = *top_node;
	*top_node = temp->next;
	if (*top_node != NULL)
		(*top_node)->prev = NULL;
	free(temp);
}


/**
 * peak - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of of the opcode.
 */
void peak(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error_stack(6, line_number);
	printf("%d\n", (*stack)->n);
}


/**
 * display_stack - display  the stack.
 * @top_node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void display_stack(stack_t **top_node, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (top_node == NULL)
		exit(EXIT_FAILURE);
	temp = *top_node;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


