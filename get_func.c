#include "monty.h"
/**
 * _strcmp - compares two strings for equality
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if equal, 0 if not equal
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}

	return (1);
}

/** get_func - identifies correct opcode function
 * @code: opcode
 *
 * Return: function corresponding to that opcode
 */
void (*get_func(char *code))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t inst[] = {
		{"push", _push},
		{"pop", _pop},
		{"nop", _nop},
		{"pall", _pall},
		{"pint", _pint},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"swap", _swap},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{NULL, NULL}
	};

	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (_strcmp(code,inst[i].opcode))
			return (inst[i].f);
	}
	++i;	
	return (inst[i].f);
}
