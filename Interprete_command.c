#include "main.h"
/**
 * Run_Command - This function runs the command
 *
 * @command: Command
 */
int Run_Command(command_t *command, char *input, char **argv, int counter_error)
{
	command_t *head = NULL;
	int status = 0;
	pid_t child_pid = 0;
	size_t counter = 0, index = 0;
	char **args = NULL;

	head = command;
	counter = Elements_Counter(command);
	args = _calloc(counter + 1, sizeof(char *));
	if (!args)
	{
		return (0);
	}
	while (command)
	{
		args[index] = command->args;
		command = command->next;
		index++;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(argv[0]);
		return (1);
	}
	else if (child_pid == 0)
	{
		status = execve(args[0], args, environ);
		if (status == -1)
		{
			fprintf(stderr, "%s: %d: %s: Permission denied\n", argv[0], counter_error, args[0]);
		}
		free(input);
		Free_Grid(args);
		Free_List(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, WUNTRACED);
	}
	Free_List(head);
	Free_Grid(args);
	return (status);
}