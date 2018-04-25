#include "monty.h"

/**
 * _add - adds the top two elements in the stack
 * and replaces both nodes with the sum
 * @stack: stack
 * @line_number: line number
 */

void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if ( *stack == NULL || (*stack)->next == NULL)
	{
		printf("L<%u>: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = ((*stack)->next)->n + (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * _sub - subtracts the top element in the stack from the next top element
 * and replaces the top two nodes with the result
 * @stack: stack
 * @line_number: line number
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if ( *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = ((*stack)->next)->n - (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = sub;
}

/**
 * _mul - multiplies the top two elements in the stack
 * and replaces both nodes with the product
 * @stack: stack
 * @line_number: line_number
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if ( *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = ((*stack)->next)->n * (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = mul;
}

/**
 * _div - divides the top of the stack by the next element in the stack
 * and replaces the top two nodes in the stack by the dividend
 * @stack: stack
 * @line_number: line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ( *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	div = ((*stack)->next)->n / (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * _mod - finds the remainder when the top element in the stack is divided by
 * the next element and replaces both nodes with that result
 * @stack: stack
 * @line_number: line number
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int mod;
	
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ( *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = ((*stack)->next)->n % (*stack)->n;

	_pop(stack, line_number);
	(*stack)->n = mod;
}
