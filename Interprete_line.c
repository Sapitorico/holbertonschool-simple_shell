#include "main.h"
/**
 * main - main function that executes the prompt
 *
 * @argv: main argument containing the name of the executable
 * @argc: arguments counter
 * Return: EXIT_SUCCESS
 */
int main(__attribute((unused))int argc, char **argv)
{
	command_t *tokens_input = NULL, *command = NULL;
	char *input = NULL;
	int status = 0, count_error = 1, not_file = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDERR_FILENO, PID, _strlen(PID));
		input = Read_Line(not_file);
		if (!input)
			break;
		tokens_input = Input_Tokenize(input);
		if (!tokens_input)
		{
			free(input);
			continue;
		}
		if (!_strcmp(tokens_input->args, "env"))
		{
			Print_Environ(tokens_input, input);
			continue;
		}
		command = Concatenate_Command(tokens_input);
		if (!command)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
					argv[0], count_error++, tokens_input->args);
			Free_List(tokens_input);
			free(input);
			not_file = 1;
			continue;
		}
		else
			not_file = 0;
		status = Run_Command(command, input, argv, count_error);
		if (status == 0)
			count_error++;
		printf("%d\n", status);
		free(input);
	}
	exit(EXIT_SUCCESS);
}
/**
 * Read_Line - Read the input line and keep it in a buffer
 *
 * @not_file: Error indicator
 * Return: buffer
 */
char *Read_Line(int not_file)
{
	char *input = NULL;
	size_t size = 0;

	if (not_file == 0)
	{
		if (getline(&input, &size, stdin) == -1)/*Condition EOF*/
		{
			free(input);
			exit(0);
		}
		else if (!_strcmp(input, "exit\n"))
		{
			free(input);
			exit(0);
		}
	}
	else if (not_file == 1)
	{
		if (getline(&input, &size, stdin) == -1)/*Condition EOF*/
		{
			free(input);
			exit(127);
		}
		else if (!_strcmp(input, "exit"))
		{
			free(input);
			exit(2);
		}
	}
	return (input);
}
/**
 * Input_Tokenize - divide the input into multiple nodes
 * @input: input line
 *
 * Return: A pointer to the first node on the list
 */
command_t *Input_Tokenize(char *input)
{
	command_t *head = NULL;
	char *token = NULL;

	token =  strtok(input, DELIMS);/*se tokenize el input*/
	while (token)
	{
		Add_Node_End(&head, token);/*new node is added the end of the list*/
		token = strtok(NULL, DELIMS);
	}
	return (head);
}
/**
 * Print_Environ - condition that prints in Environment
 *
 * @tokens_input: lista de arguemntos
 * @input: input
 */
void Print_Environ(command_t *tokens_input, char *input)
{
	_printenv();
	Free_List(tokens_input);
	free(input);
}
