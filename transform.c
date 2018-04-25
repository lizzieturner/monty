#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int swap;

	if ((*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;
}

/**
 * _rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: line number
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
        UNUSED(line_number);
}

/**
 * _rotr - prints the char at the top of the stack, followed 
 * by a new line
 * @stack: stack
 * @line_number: line_number
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
        UNUSED(line_number);
}
