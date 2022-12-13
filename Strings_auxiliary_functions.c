#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: pinter to address os string
 *
 * Return: all elements of the string
 */
int _strlen(char *s)
{
	int count = 0;

	for (; s[count]; count++)
		;
	return (count);
}
/**
 * str_len - returns the length of a string
 * @s: pinter to addres os strign
 *
 * Return: all elements of the stirng
 */
int str_len(const char *s)
{
	int count = 0;

	for (; s[count]; count++)
		;
	return (count);
}
/**
 * *_strcpy -  function that copies the string
 * @src: pointer to the string
 * @dest: string copy destination
 *
 * Return: returns copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *copy = dest;

	while ((*copy++ = *src++) != '\0')
		;
	return (dest);
}
/**
 * _strcat - concatenates two strings
 * @dest: pointer to the target strings to be concatenated
 * @src: pointer to the string to concatenate
 *
 * Return: the concatenated character string
 */
char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int i;

	for (i = 0; i < _strlen(src); i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings
 * @s1: pointer to the compared string
 * @s2: pointer to comparison string
 * Return: difference of characters in their ASCII numeric value or 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
