#include "monty.h"
#define MAX_BUFF 100000
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
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
				return (-1);
			spacecheck = 1;
		}
		else
		{
			if (spacecheck == 1)
				return (0);
		}
		i++;
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
	char *error;
	
	/* trim leading whitespaces with token */
	while (isspace(*token))
		token++;
	if (token[0] == '#')
		return;
	if (strncmp(token, "push ", 5) == 0)
	{
		while (isalpha(*token))
			token++;
		if (num_check(token) == -1)
		{
			printf("L%u: usage: push integer\n", lines);
			free_list(stack);
			free(stack);
			exit(EXIT_FAILURE);
		}
		if (token[0] == '-')
			num = atoi(token) * -1;
		else
			num = atoi(token);
		token = "push";
	}

	func = get_func(token);
	if (func == NULL)
	{
		error = strndup(token, 4);
		printf("L%u: unknown instruction %s\n", lines, error);
		free_list(stack);
		free(stack);
		free(error);
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
			printf("Error: Can't open file %s\n", file);
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
