#include "monty.h"
int num;
/**
 * _push - adds a new element to the top of the stack
 * @stack: stack
 * @line_number: line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)line_number;
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		printf(ERROR_MALLOC);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	top->n = num;
	top->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = top;
		top->next = *stack;
	}
	else
		top->next = NULL;
	*stack = top;
}
/**
* _pop - removes the top element of the stack
* @stack: stack
* @line_number: line number
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}

/**
 * _nop - does nothing
 * @stack: stack
 * @line_number: line number
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
