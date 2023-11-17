#include "monty.h"

/**
 * multi_nodes - multiplications the top two nodes of the stack.
 * @stack:  pointer pointing to top node of the stack.
 * @line_num: the line number of of the opcode.
 */
void multi_nodes(stack_t **top_node, unsigned int line_num)
{
	int multi;

	if (top_node == NULL || *top_node == NULL || (*top_node)->next == NULL)
		error_stack(8, line_num, "mul");

	(*top_node) = (*top_node)->next;
	multi = (*top_node)->n * (*top_node)->prev->n;
	(*top_node)->n = multi;
	free((*top_node)->prev);
	(*top_node)->prev = NULL;
}


/**
 * nodes_division - division nodes.
 * @top_node: pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void nodes_division(stack_t **top_node, unsigned int line_num)
{
	int divi;

	if (top_node == NULL || *top_node == NULL || (*top_node)->next == NULL)
		error_stack(8, line_num, "div");

	if ((*top_node)->n == 0)
		error_stack(9, line_num);
	(*top_node) = (*top_node)->next;
	divi = (*top_node)->n / (*top_node)->prev->n;
	(*top_node)->n = divi;
	free((*top_node)->prev);
	(*top_node)->prev = NULL;
}