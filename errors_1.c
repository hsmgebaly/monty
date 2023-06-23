include "monty.h"

int malloc_error(void);
int usage_error(void);
int f_open_error(char *filename);
int no_int_error(unsigned int line_number);
int unknown_op_error(char *opcode, unsigned int line_number);

/**
 * usage_error - For printing the usage error messages
 * Return: Always return (EXIT_FAILURE)
 */

int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - For printing the malloc error messages
 * Return: Always return (EXIT_FAILURE)
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - For Printing file opening error messages w/ file name
 * @filename: Name of file which failed to open
 * Return: Always return (EXIT_FAILURE)
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - For printing the unknown instruction error messages.
 * @opcode: Opcode that happened when error occurred
 * @line_number: Line number in the monty bytecodes file which happened
 * where error occured
 * Return: Always return (EXIT_FAILURE)
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - For printing the invalid monty_push argument error messages
 * @line_number: Line number in the monty bytecodes file which happened
 * where error occured
 * Return: Always return (EXIT_FAILURE)
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
