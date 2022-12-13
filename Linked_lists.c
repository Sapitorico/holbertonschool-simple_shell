#include "main.h"
/**
 * Add_Node - This function adds a new node
 *
 * @head: A pointer to the head of the list
 * @input: The string to be added to the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
command_t *Add_Node(command_t **head, char *input)
{
	command_t *node = NULL;

	node = malloc(sizeof(command_t));
	if (!node)
		return (NULL);
	node->args = _strdup(input);
	if (!node->args)
		return (NULL);
	node->len = _strlen(input);
	node->next = *head;
	*head = node;
	return (node);
}
/**
 * Add_Node_End - This function adds a node to the end of a list
 *
 * @head: A pointer to the head of the list
 * @input: The string to be added to the new node
 *
 * Return: The address of the last element, or NULL if failed
 */
command_t *Add_Node_End(command_t **head, char *input)
{
	command_t *end = NULL, *node = *head;

	if (!node)
	{
		*head = Add_Node(head, input);
		return (*head);
	}
	while (node->next)
		node = node->next;
	end = Add_Node_End(&(node->next), input);
	return (end);
}
/**
 * Elements_Counter - Counts the number of elements in a list
 *
 * @head: The string to be added to the new node
 *
 * Return: Number of elements
 */
size_t Elements_Counter(command_t *head)
{
	size_t counter = 0;

	while (head)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}
/**
 * Free_List - release the elements of a list
 *
 * @head: A pointer to the head of the list
 */
void Free_List(command_t *head)
{
	command_t *node = head;

	while (head)
	{
		head = head->next;
		free(node->args);
		free(node);
		node = head;
	}
}
/**
 * Free_Grid - Free a array of pointers
 *
 * @grid: array of pointers
 */
void Free_Grid(char **grid)
{
	int index = 0;

	if (!grid)
		return;
	for (; index < 0; index++)
		free(grid[index]);
	free(grid);
}
