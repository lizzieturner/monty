#include "monty.h"
#define MAX_BUFF 1024

void stack_it(char *file)
{
	int lines;
	char *stream, *token;
	stack_t **stack;
	
	/* assigning NULL to our linked list */
	stack = NULL;
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
}	


void find_op(stack_t **stack, int lines, char *token)
{
	char *copy_token;
	void (*func)(stack_t **stack_size, unsigned int line_number);
	(void)stack;
	/* trim leading whitespaces with token */
	while (isspace(*token))
		token++;
	printf("First token: %s\n", token);
	copy_token = strdup(token);
	(void)copy_token;
	if (strncmp(token, "push", 4) == 0)
	{
		/* find the number, change to atoi, set it as the global variable */
		printf("%s\n", token);	
		/*
		// when you uncomment out this code, it won't print past the first command, it will stop on the first command and then not execute.
		// I think it the strtok on the str_num is somehow affecting the token being parsed to the function. Not sure why because it's a copy with new memory because strdup mallocs new memory for the string pointer
		str_num = strtok(copy_token," ");
		str_num = strtok(NULL, " ");
		num = atoi(str_num);	
		printf("Num: %d\n", num);
		*/
		func = get_func("push");
	}
	else
	{
		printf("%s\n", token);
		func = get_func(token);
	}
	if (func == NULL)
	{
		printf("L%d: unknown instruction %s\n", lines, token);
		exit(EXIT_FAILURE);
	}

	/*func(stack, lines);*/
}

char *read_file(char *file)
{
	FILE *f;
	char buff[MAX_BUFF + 1];
	size_t newLen = 0;
	char *buff_point;

	f = fopen(file, "r");	
	if (f != NULL)
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

	buff_point = buff;
	fclose(f);
	return buff_point;
}
