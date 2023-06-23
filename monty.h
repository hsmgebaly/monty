#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* 1st The global OPCODE token */

extern char **op_toks;

/**
 * struct stack_s - Stack (or queue) representation as a doubly linked list
 * @n: for the integer
 * @prev: refers to the stack's (or queue's) previous entry.
 * @next: refers to the next element of the stack (or queue)
 * Description: for the Holberton project's stack, queues, LIFO, and FIFO,
 * a doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Refers to the opcode and its function
 * @opcode: for the opcode
 * @f: For the function which handle the opcode
 * Description: the opcode and its function for stack,
 * queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* 2nd THE PRIMARY FUNCTIONS OF INTERPRETER */

int init_stack(stack_t **stack);
void free_stack(stack_t **stack);
void set_op_tok_error(int error_code);
int check_mode(stack_t *stack);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
void free_tokens(void);

/* 3rd The OPCODE Function */

void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);
void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);

/* 4th The CUSTOM STANDARD LIBRARY FUNCTIONS */

char *get_int(int n);
char **strtow(char *str, char *delims);

/* 5th THE ERROR MESSAGES and ERROR CODES */

int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int malloc_error(void);
int f_open_error(char *filename);
int usage_error(void);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);

#endif /* __MONTY_H__ */