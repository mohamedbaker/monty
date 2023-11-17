#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)

 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void op_file(char *file_name);
int l_parse(char *buffer, int line_number, int format);
void readFile(FILE *);
int len_chars(FILE *);
void connect_func(char *, char *, int, int);

void error_files(int error_code, ...);
void error_stack(int error_code, ...);
void error_str(int error_code, ...);
void rot_up(stack_t **, unsigned int);

stack_t *create_newNode(int n);
void free_linkedList(void);
void display_stack(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void add_NodeTo_queue(stack_t **, unsigned int);

void get_fun(op_func, char *, char *, int, int);

void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void peak(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

void sum_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void nodes_division(stack_t **, unsigned int);
void multi_nodes(stack_t **, unsigned int);
void modu_nodes(stack_t **, unsigned int);

void printCh(stack_t **, unsigned int);
void printStr(stack_t **, unsigned int);
void rot_shift(stack_t **, unsigned int);

#endif
