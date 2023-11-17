#include "monty.h"


/**
 * swap - Swaps the top two nodes of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num:  line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_stack(8, line_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * nop - do nothing.
 * @top_node: Pointer to a pointer pointing to top node of the stack.
 * @line_num:  line number of of the opcode.
 */
void nop(stack_t **top_node, unsigned int line_num)
{
	(void)top_node;
	(void)line_num;
}



/**
 * sum_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_num:  line number of of the opcode.
 */
void sum_nodes(stack_t **top_node, unsigned int line_num)
{
	int sum;

	if (top_node == NULL || *top_node == NULL || (*top_node)->next == NULL)
		error_stack(8, line_num, "add");

	(*top_node) = (*top_node)->next;
	sum = (*top_node)->n + (*top_node)->prev->n;
	(*top_node)->n = sum;
	free((*top_node)->prev);
	(*top_node)->prev = NULL;
}


/**
 * modu_nodes - modules the top two nodes of the stack.
 * @top_node: pointer pointing to top node of the stack.
 * @line_num:  line number of of the opcode.
 */
void modu_nodes(stack_t **top_node, unsigned int line_num)
{
	int modul;

	if (top_node == NULL || *top_node == NULL || (*top_node)->next == NULL)

		error_stack(8, line_num, "mod");

	if ((*top_node)->n == 0)
		error_stack(9, line_num);
	(*top_node) = (*top_node)->next;
	modul = (*top_node)->n % (*top_node)->prev->n;
	(*top_node)->n = modul;
	free((*top_node)->prev);
	(*top_node)->prev = NULL;
}


/**
 * sub_nodes - sub the top two nodes of the stack.
 * @top_node:  pointer pointing to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void sub_nodes(stack_t **top_node, unsigned int line_num)
{
	int sum_nodes;

	if (top_node == NULL || *top_node == NULL || (*top_node)->next == NULL)

		error_stack(8, line_num, "sub");

	(*top_node) = (*top_node)->next;
	sum_nodes = (*top_node)->n - (*top_node)->prev->n;
	(*top_node)->n = sum_nodes;
	free((*top_node)->prev);
	(*top_node)->prev = NULL;
}


