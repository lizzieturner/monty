#include "monty.h"

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
