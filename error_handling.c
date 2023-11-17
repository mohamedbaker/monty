#include "monty.h"

/**
 * error_files - prints the right error msg.
 * @error_code: error num code.
 */
void error_files(int error_code, ...)
{
	va_list args;
	char *operator;
	int l_count;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			l_count = va_arg(args, int);
			operator = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_count, operator);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_linkedList();
	exit(EXIT_FAILURE);
}

/**
 * error_stack - handles errors for the stack.
 * @error_code: The error num code:
 */
void error_stack(int error_code, ...)
{
	va_list args;
	char *operator;
	int l_count;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			l_count = va_arg(args, unsigned int);
			operator = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_count, operator);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_linkedList();
	exit(EXIT_FAILURE);
}

/**
 * error_str - handles strings errors.
 * @error_code: The error num code
 */
void error_str(int error_code, ...)
{
	va_list args;
	int l_count;

	va_start(args, error_code);
	l_count = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_count);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_count);
			break;
		default:
			break;
	}
	free_linkedList();
	exit(EXIT_FAILURE);
}
