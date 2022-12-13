#include "main.h"
/**
 * Concatenate_Command - This function obtains the direction of the command
 *
 * @tokens_input: Inputs Elements
 *
 * Return: The address of the commander or null in case of fault
 */
command_t *Concatenate_Command(command_t *tokens_input)
{
	command_t *dirs = NULL, *head_dir = NULL;
	char *command_concat = NULL;
	struct stat stats;

	if (!stat(tokens_input->args, &stats))
		return (tokens_input);
	dirs = Path_Tokenize();
	head_dir = dirs;
	while (dirs)
	{
		command_concat = _calloc(dirs->len + tokens_input->len + 2, sizeof(char));
		if (!command_concat)
		{
			Free_List(head_dir);
			return (NULL);
		}
		command_concat = _strcpy(command_concat, dirs->args);
		command_concat = _strcat(command_concat, "/");
		command_concat = _strcat(command_concat, tokens_input->args);
		if (!stat(command_concat, &stats))
		{
			Free_List(head_dir);
			free(tokens_input->args);
			tokens_input->args = command_concat;
			return (tokens_input);
		}
		free(command_concat);
		dirs = dirs->next;
	}
	Free_List(head_dir);
	return (NULL);
}
/**
 * Path_Tokenize - Divide directories into multiple elements
 *
 * Return: The address of the first dir
 */
command_t *Path_Tokenize(void)
{
	char *path = NULL;
	char *token = NULL;
	command_t *head = NULL;
	int counter = 0;

	path = _getenv("PATH");
	token = strtok(path, DELIMS);
	while (token)
	{
		Add_Node_End(&head, token);
		token = strtok(NULL, DELIMS);
		counter++;
	}
	free(path);
	return (head);
}
/**
 * _getenv - This function obtains the value of an environment variable
 *
 * @name: Variable name
 * Return: The directories of the variable or null if it
 */
char *_getenv(const char *name)
{
	int index = 0, dirs = 0;
	char *ptr = NULL;

	while (environ[index])
	{
		while (environ[index][dirs] == name[dirs] && name[dirs] != '\0')
			dirs++;
		if (name[dirs] == '\0' && environ[index][dirs] == '=')
		{
			ptr = _calloc(_strlen(environ[index]), sizeof(char));
			if (!ptr)
				return (NULL);
			_strcpy(ptr, &(environ[index][str_len(name) + 1]));
			return (ptr);
		}
		index++;
		dirs = 0;
	}
	return (NULL);
}
