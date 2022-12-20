#include "shell.h"

/**
 *_strcmp -   compares two strings
 *@s1: value pointers
 *@s2: value pointers
 *Return: Return value poiners dest
 */
int _strcmp(char *s1, char *s2)

{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

/**
 *_strlen - takes a string as an argument and returns its length
 *@s: value pointers
 *Return: Return value i
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *s != '\0'; i++)
	{
		s++;
	}
	return (i);
}
/**
 *_strcpy - Function that copy the string
 *@src: value pointers
 *@dest: value pointers
 *Return: Return value pointers
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 *_getenv - Function  get an environment variable
 *@name: value pointers const char
 *Return: Return value pointers char
 */
char *_getenv(const char *name)
{
	int i, j;
	int status;
	extern char **environ;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (NULL);
}

/**
**_strcat - Concatenate two strings
*@dest: Variable of the destination
*@src: Variable of the string
*
*Return: Always 0
*/

char *_strcat(char *dest, char *str)
{
	int i = 0;
	int j = 0;

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