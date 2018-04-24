#include "monty.h"

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
		if (code == inst[i].opcode)
			return (inst[i].f);
	}
	
	return (inst[i].f);
}
