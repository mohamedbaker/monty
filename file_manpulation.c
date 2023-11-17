#include "monty.h"

/**
 * op_file - open the file
 * @file_path: the file path
 * Return: void
 */

void op_file(char *file_path)
{
	FILE *fd = fopen(file_path, "r");

	if (file_path == NULL || fd == NULL)
		error_files(2, file_path);

	readFile(fd);
	fclose(fd);
}


/**
 * readFile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void readFile(FILE *fd)
{
	int l_number, format = 0;
	char *bf = NULL;
	size_t len = 0;

	for (l_number = 1; getline(&bf, &len, fd) != -1; l_number++)
	{
		format = l_parse(bf, l_number, format);
	}
	free(bf);
}


/**
 * get_fun - gets  required function.
 * @func_to_call: Pointer to the function
 * @operator: string for the opcode.
 * @val: string for a numeric val.
 * @line_num: line numeber for the instruction.
 * @format_DS: format specifier. if 0 stack if 1 queue.
 */
void get_fun(op_func func_to_call, char *operator, char *val, int line_num, int format_DS)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(operator, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error_files(5, line_num);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error_files(5, line_num);
		}
		node = create_newNode(atoi(val) * flag);
		if (format_DS == 0)
			func_to_call(&node, line_num);
		if (format_DS == 1)
			add_NodeTo_queue(&node, line_num);
	}
	else
		func_to_call(&head, line_num);
}

/**
 * l_parse - parse each line
 * @bf: buffer
 * @l_number: line number
 * @format_DS:  choose stack or queue.
 * Return: Returns 0 if stack. 1 if queue.
 */

int l_parse(char *bf, int l_number, int format_DS)
{
	char *op_code, *value;
	const char *delima = "\n ";

	if (bf == NULL)
		error_files(4);

	op_code = strtok(bf, delima);
	if (op_code == NULL)
		return (format_DS);
	value = strtok(NULL, delima);

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);

	connect_func(op_code, value, l_number, format_DS);
	return (format_DS);
}

/**
 * connect_func - connect  function for the opcode
 * @op_code: opecode
 * @val: argument of opcode
 * @format_DS:  storage format. If 0 a stack.
 * @line_num: line number
 * Return: void
 */
void connect_func(char *op_code, char *val, int line_num, int format_DS)
{
	int indx;
	int flag;

	instruction_t func_list[] = {
		{"push", push},
		{"pall", display_stack},
		{"pint", peak},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", sum_nodes},
		{"sub", sub_nodes},
		{"div", nodes_division},
		{"mul", multi_nodes},
		{"mod", modu_nodes},
		{"pchar", printCh},
		{"pstr", printStr},
		{"rotl", rot_shift},
		{"rotr", rot_up},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;

	for (flag = 1, indx = 0; func_list[indx].opcode != NULL; indx++)
	{
		if (strcmp(op_code, func_list[indx].opcode) == 0)
		{
			get_fun(func_list[indx].f, op_code, val, line_num, format_DS);
			flag = 0;
		}
	}
	if (flag == 1)
		error_files(3, line_num, op_code);
}