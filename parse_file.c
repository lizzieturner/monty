#include "monty.h"
#define MAX_BUFF 1024
/**
 * stack_it - creates a linked list of all the commands per line from
 * input file
 * @file: file to parse and created a linked list with
 */
void stack_it(char *file)
{
	int lines;
	char *stream, *token;
	stack_t **stack;

	stack = malloc(sizeof(char *));
	if (stack == NULL)
	{
		printf(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}
	/*creating a stream to then turn into tokens*/
	stream = read_file(file);

	/*tokenizing each line to then pass to each function*/
	token = strtok(stream, "\n");
	lines = 1;
	while (token)
	{
		find_op(stack, lines, token);
		++lines;
		token = strtok(NULL, "\n");
	}
	/*free the linked list*/
	free_list(stack);
	free(stack);
}

/**
 * free_list - free's the linked list created by stack_it
 * @stack: the stack to free
 */
void free_list(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

/**
 * num_check - checks if push argument is a number
 * @str: argument
 *
 * Return: 0 if it is a number, -1 otherwise
 */

int num_check(char *str)
{
	int i = 0, spacecheck = 0;

	if (str[i] == ' ')
		i++;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			i++;
		else
			spacecheck = 1;

		if (isdigit(str[i]) == 0)
			return (-1);
	}
	if (spacecheck == 0)
		return (-1);
	return (0);
}


/**
 * find_op - trims white space between each command, creates a token that is
 * then sent to get_func to find the associated function, atoi from each of the
 * input arguments from push
 * @stack: the stack linked list
 * @lines: the line numbers of each file
 * @token: each token from the strtok file
 */
void find_op(stack_t **stack, int lines, char *token)
{
	void (*func)(stack_t **stack_size, unsigned int line_number);
	/* trim leading whitespaces with token */
	while (isspace(*token))
		token++;
	if (strncmp(token, "push", 4) == 0)
	{
		/* find the number, change to atoi, set it as the global variable */
		while (isalpha(*token))
			token++;
		if (num_check(token) == -1)
		{
			printf("L%u: usage: push integer\n", lines);
			free_list(stack);
			free(stack);
			exit(EXIT_FAILURE);
		}
		num = atoi(token);
		func = get_func("push");
	}
	else
	{
		if (token[0] == '#')
			func = get_func("nop");
		else
			func = get_func(token);
	}
	if (func == NULL)
	{
		printf("L%d: unknown instruction %s\n", lines, token);
		free_list(stack);
		free(stack);
		exit(EXIT_FAILURE);
	}

	func(stack, lines);
}

/**
 * read_file - reads a file from argv1, copies contents into a buffer
 * @file: file to read
 *
 * Return: pointer to the buffer
 */
char *read_file(char *file)
{
	FILE *f;
	char buff[MAX_BUFF + 1];
	size_t newLen = 0;
	char *buff_point;

	f = fopen(file, "r");
	if (f)
	{
		newLen = fread(buff, sizeof(char), MAX_BUFF, f);
		if (ferror(f) != 0)
		{
			printf(ERROR_FILE);
			printf("%s\n", file);
			exit(EXIT_FAILURE);
		}
		else
			buff[newLen++] = '\0';
	}
	else
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}

	buff_point = buff;
	fclose(f);
	return (buff_point);
}
