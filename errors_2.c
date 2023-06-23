#include "monty.h"

int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int div_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);


/**
 * pop_error - For printing the pop error messages for the empty stacks
 * @line_number: Line number in the monty bytecodes file which happened
 * where error occured
 * Return: Always return (EXIT_FAILURE)
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - For printing the pint error messages for the empty stacks
 * @line_number: Line number in the monty bytecodes file which happened
 * where error occured
 * Return: Always return (EXIT_FAILURE)
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - For printing the monty math function error messages
 * for stacks/queues which are smaller than two nodes
 * @line_number: Line number in the monty bytecodes file which happened
 * where error occured
 * @op: the Operation which happened where the error occurred
 *
 * Return: Always return (EXIT_FAILURE)
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - For printing division error messages for division by 0.
 * @line_number: Line number in the monty bytecodes file which happened
 * where error occured
 * Return: Always return (EXIT_FAILURE)
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - For printing pchar error messages for the empty stacks
 * empty stacks & non-character values
 * @line_number: Line number in the monty bytecodes file which happened
 * where error occured
 * @message: The corresponding error message which will be printed
 * Return: Always return (EXIT_FAILURE)
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
