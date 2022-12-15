#include "monty.h"
#include <unistd.h>

/**
 * main - Main Entry Point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: (0) always Successful
 */

int  main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *stream;
	char *token, *arg, *line = NULL;
	size_t len = 0;
	int line_number = 0;
	ssize_t nread;
	void (*f)(stack_t **stack, unsigned int line_number);
    	stack_t *head;

    	head = NULL;

	if (argc != 2)
	{
		write(2, "hello", 5);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		perror("fopen");
		fprintf(stderr, "Error: Can't open %s <file>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{

		line_number++;

		if (strcmp(line, "\n") == 0)
			continue;
		token = strtok(line, "\n");
		token = strtok(token, " ");

		if (token == NULL)
			continue;
		arg = strtok(NULL, " ");

		if (arg)
			val = atoi(arg);
		f = get_stack_call(token);
		if (f == NULL)
		{
			printf("Not Found: Line %d \n", line_number);
		}

		f(&stack, line_number);

	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
