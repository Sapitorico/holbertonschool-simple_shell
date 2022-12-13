#ifndef MAIN_H
#define MAIN_H
/*Libraries*/
#include <stdio.h>/*It contains the definitions of the macros, the constants,*/
/*the statements of functions of the standard library*/
#include <stdlib.h>/*Contains the prototypes of*/
/* C functions for dynamic memory management*/
#include <limits.h>/*Determine several properties of*/
/* the different types of variables*/
#include <unistd.h>/*Define constant and miscellaneous symbolic types*/
/* and declare miscellaneous functions*/
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
/*macros*/
#define PID "#cisfun$ "
#define DELIMS " :\n\t"
extern char **environ;
/**
 * struct command_s - simple linked list for arguments and directories
 *
 * @args: pointer containing the string of the argument or directory
 * @len: length of the string
 * @next: pointer to the next node
 */
typedef struct command_s
{
	char *args;
	unsigned int len;
	struct command_s *next;
} command_t;

/*Prototypes*/

/*Interprete Line*/

char *Read_Line(int not_file);/*Function to read the input*/

command_t *Input_Tokenize(char *input);/*Tokenize the input*/

/*Get Command*/

command_t *Concatenate_Command(command_t *tokens_input);
/*concatenate the path with the input*/

command_t *Path_Tokenize(void);/*Divide the PATH into directories*/

/*Interprete Command*/

/*Execute the commands*/
int Run_Command(command_t *command, char *input, char **argv, int count_error);

/*Linked Lists*/

command_t *Add_Node(command_t **head, char *input);/*Add a node*/

command_t *Add_Node_End(command_t **head, char *input);
/*Add a node at the end of the list*/

size_t Elements_Counter(command_t *head);/*Count the number of nodes*/

void Free_List(command_t *head);/*Release a list*/

void Free_Grid(char **grid);/*Free a array of pointers*/

/*getenv*/

char *_getenv(const char *name);

/*Auxiliary functions*/

int _strlen(char *s);/*Long of a string*/

int str_len(const char *s);

char *_strcpy(char *dest, char *src);/*Copy a string*/

char *_strcat(char *dest, char *src);/*concatenate two strings*/

int _strcmp(char *s1, char *s2);/*Compare two strings*/

char *_strdup(char *str);/*duplicate a string*/

void *_calloc(unsigned int nmemb, unsigned int size);

char *_memset(char *s, char b, unsigned int n);

#endif
