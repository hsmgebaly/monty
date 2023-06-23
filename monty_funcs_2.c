#include "monty.h"

void monty_sub(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - For adding the top two values of the stack_t linked list
 * @stack: Refere to the top mode node of the stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 * Description: The result will be stored in the 2nd value node
 * from the top & the top value will be removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - For subtracting the second value from the top of
 * a stack_t linked list by the top value.
 * @stack: Refere to the top mode node of the stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 * Description: The result will be stored in the 2nd value node
 * from the top & the top value will be removed
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - For Dividing the 2nd value from the top of
 * a stack_t linked list by the top value.
 * @stack: Refere to the top mode node of the stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 * Description: The result will be stored in the 2nd value node
 * from the top & the top value will be removed
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - For Multipling the 2nd value from the top of
 * a stack_t linked list by the top value.
 * @stack: Refere to the top mode node of the stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 * Description: The result will be stored in the 2nd value node
 * from the top & the top value will be removed
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - For computing the modulus of the 2nd value from the
 * top of a stack_t linked list by the top value.
 * @stack: Refere to the top mode node of the stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 * Description: The result will be stored in the 2nd value node
 * from the top & the top value will be removed
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
