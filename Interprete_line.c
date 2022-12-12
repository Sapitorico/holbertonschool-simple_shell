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
	int status = 0, counter_error = 1, size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDERR_FILENO, PID, _strlen(PID));
		input = Read_Line();
		if (!input)
			break;
		tokens_input = Input_Tokenize(input);
		if (!tokens_input)
		{
			free(input);
			continue;
		}
		command = Concatenate_Command(tokens_input);
		if (!command)
		{
			if (!_strcmp(tokens_input->args, "\""))
			{
				size = _strlen(tokens_input->args);
				free(tokens_input->args);
				tokens_input->args = _calloc(size, sizeof(char));
			}
			fprintf(stderr, "%s: %d: %s: not found\n",
					argv[0], counter_error++, tokens_input->args);
			Free_List(tokens_input);
			free(input);
			continue;
		}
		status = Run_Command(command, input, argv, counter_error);
		if (status > 0)
			counter_error++;
		free(input);
	}
	return (0);
}
/**
 * Read_Line - Read the input line and keep it in a buffer
 *
 * Return: buffer
 */
char *Read_Line(void)
{
	char *input = NULL;
	size_t size = 0;

	if (getline(&input, &size, stdin) == -1)/*Condition EOF*/
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(input);
		exit(EXIT_FAILURE);
	}
	else if (!_strcmp(input, "exit\n"))
	{
		free(input);
		return (NULL);
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
