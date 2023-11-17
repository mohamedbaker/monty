#include "monty.h"

/**
 * printCh - Prints Ascii.
 * @top_node: pointer to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void printCh(stack_t **top_node, unsigned int line_num)
{
	int ch;

	if (top_node == NULL || *top_node == NULL)
		error_str(11, line_num);

	ch = (*top_node)->n;
	if (ch < 0 || ch > 127)
		error_str(10, line_num);
	printf("%c\n", ch);
}

/**
 * printStr - Prints  string.
 * @top_node: pointer  to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void printStr(stack_t **top_node, __attribute__((unused))unsigned int line_num)
{
	int ch;
	stack_t *temp;

	if (top_node == NULL || *top_node == NULL)
	{
		printf("\n");
		return;
	}

	temp = *top_node;
	while (temp != NULL)
	{
		ch = temp->n;
		if (ch <= 0 || ch > 127)
			break;
		printf("%c", ch);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rot_up - Rotate  last node of the stack to the top.
 * @top_node: pointer to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void rot_up(stack_t **top_node, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp;

	if (top_node == NULL || *top_node == NULL || (*top_node)->next == NULL)
		return;

	tmp = *top_node;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *top_node;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*top_node)->prev = tmp;
	(*top_node) = tmp;
}


/**
 * rot_shift - Rotates the first node of the stack to the end.
 * @top_node: pointer  to top node of the stack.
 * @line_num: line number of of the opcode.
 */
void rot_shift(stack_t **top_node, __attribute__((unused))unsigned int line_num)
{
	stack_t *temp;

	if (top_node == NULL || *top_node == NULL || (*top_node)->next == NULL)
		return;

	temp = *top_node;
	while (temp->next != NULL)
		temp = temp->next;


	temp->next = *top_node;
	(*top_node)->prev = temp;
	*top_node = (*top_node)->next;
	(*top_node)->prev->next = NULL;
	(*top_node)->prev = NULL;
}


