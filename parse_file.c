#include "monty.h"
#define MAX_BUFF 1024

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


void free_list(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;

	while(*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

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
		exit(EXIT_FAILURE);
	}

	func(stack, lines);
}

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
	return buff_point;
}
