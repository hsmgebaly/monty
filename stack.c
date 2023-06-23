#include "monty.h"
#include <string.h>

int init_stack(stack_t **stack);
void free_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - sets a stack_t stack free.
 * @stack: a pointer to a stack_t's top (stack)
 * or bottom (queue).
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - creates beginning stack and finishing
 * queue nodes for a stack_t stack.
 * @stack: a unitialized stack_t stack pointer.
 * Return: The error code is EXIT_FAILURE.
 * If not, EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - determines the mode of a stack_t linked list,
 * either stack or queue.
 * @stack: a pointer to the stack or queue at the top
 * or bottom of a stack_t linked list.
 * Return: Stack(0) if the stack_t is in stack mode.
 *         QUEUE (1) if the stack_t is in queue mode.
 *         If not, 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
