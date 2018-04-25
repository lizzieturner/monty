#include "monty.h"
/**
 * _strcmp - compares two strings for equality
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if equal, 0 if not equal
 */
int _strncmp(char *s1, char *s2, int length)
{
	int i = 0;

	while (s1[i] && i < length)
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}

	return (1);
}

int find_length(char *code)
{
	int length = 0, i = 0;
	while (isalpha(code[i]))
	{
		++length;
		++i;
	}
	return length;
}

/** get_func - identifies correct opcode function
 * @code: opcode
 *
 * Return: function corresponding to that opcode
 */
void (*get_func(char *code))(stack_t **stack, unsigned int line_number)
{
	int i, length;
	
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
	
	length = find_length(code);
	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (_strncmp(code, inst[i].opcode, length))
			return (inst[i].f);
	}
	return (inst[i].f);
}
