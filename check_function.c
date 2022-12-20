#include "shell.h"
/**
**check_path - Checks if array's address exists
*@array_main: Array of addresses
*@buff: Buffer that contains command
*Return: Always 0
*/

char *check_path(char *buff)
{
	char *final_path, *string_pathcpy, **array_main;
	char *string_path = getenv("PATH");
	int j = 0, len_address;
	struct stat info;

	string_pathcpy = malloc(strlen(string_path) + 1);
	string_pathcpy = strcpy(string_pathcpy, string_path);
	array_main = _divstring(string_pathcpy, ":");

	while (array_main[j] != NULL)
	{
		len_address = strlen(array_main[j]);
		if (array_main[j][len_address - 1] != '/')
		{
			final_path = _strcatfun(array_main[j], "/");
		}

		final_path = _strcatfun(array_main[j], buff);

		if (stat(final_path, &info) == 0)
			break;
		j++;
	}
	free(string_pathcpy);
	free(array_main);
	return (final_path);
}
/**
**_divstring - Executes strtok function to get PATH
*@buff: Buffer that contains command
*@string_path: Length of command
*Return: Always 0
*/

char **_divstring(char *string_pathcpy, char *separator)
{
	int i = 0, j = 0;
	char *t;
	char **array;

	array = (char **)calloc(100, sizeof(char *));
	while (string_pathcpy[i])
		i++;
	while ((t = strtok(string_pathcpy, separator)) != NULL)
	{
		array[j] = t;
		string_pathcpy = NULL;
		j++;
	}
	return (array);
}
