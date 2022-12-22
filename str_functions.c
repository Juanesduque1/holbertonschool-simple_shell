#include "shell.h"

/**
 *_strcmp - Compares two strings
 *@s1: First string to compare
 *@s2: Second string to compare
 *Return: 0 if both strings are the same
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	return (0);
}
/**
 *_strlen - Gets a string as an argument and returns it's length
 *@s: String to get lenght from
 *Return: Lenght of a string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; i++)
		s++;

	return (i);
}
/**
 *_strcpy - Function that copies the string
 *@dest: String to copy to
 *@src: String to copy from
 *Return: Copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return (dest);
}
/**
**_strcatfun - Concatenates two strings
*@dest: Variable of the destination
*@str: Variable of the string
*Return: Concatenated string
*/

char *_strcatfun(char *dest, char *str)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (str[j] != '\0')
	{
		dest[i + j] = str[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/**
 **_calloc- function malloc and free
 *@nmemb: Quantity of elements entering the function
 *@size: Size to allocate
 *Return: Reserved variable with calloc
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *a;
	unsigned int i;

	if (nmemb == 0)
		return (NULL);

	if (size == 0)
		return (NULL);

	a = malloc(size * nmemb);

	if (a == NULL)
		return (NULL);
	for (i = 0; i < size * nmemb; i++)
		a[i] = 0;

	return (a);
}
