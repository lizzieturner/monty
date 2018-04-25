#include "monty.h"
/**
 * main - gets argv[1] file and passes it to stack_it
 *
 * @argv: argument vector
 * @argc: argument count
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf(ERROR_ARG);
		exit(EXIT_FAILURE);
	}

	stack_it(argv[1]);
	return (0);
}
