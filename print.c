#include "monty.h"

/**
 * _pall - prints all the values on the stack starting from the top
 * @stack: stack
 * @line_number: line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;

	UNUSED(line_number);

	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: stack
 * @line_number: line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pchar - prints the char at the top of the stack, followd by a new line
 * @stack: stack
 * @line_number: line_number
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
/*
		free_list(stack);
		free(stack);
*/
		exit(EXIT_FAILURE);
	}

	if (isascii(num))
		printf("%c\n", num);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
/*
		free_list(stack);
		free(stack);
*/
		exit(EXIT_FAILURE);
	}
}

/**
 * _pstr - prints the string starting at the top of the stack, followed
 * by a new line
 * @stack: stack
 * @line_number: line number
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (*stack != NULL)
	{
		if (isascii((*stack)->n) && (*stack)->n != 0)
			printf("%c", (*stack)->n);
		else
		{
			printf("\n");
			return;
		}
		*stack = (*stack)->next;
	}
	printf("\n");
}
