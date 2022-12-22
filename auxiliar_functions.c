#include "shell.h"

/**
**check_path - Checks if array's address exists
*@buff: Buffer that contains command
*Return: Path of the command if found, NULL otherwise
*/

char *check_path(char *buff)
{
	char *final_path, *string_pathcpy, **array_main;
	char *string_path = _getenv("PATH");
	int j = 0, len_address, checker = 0;
	struct stat info;

	if (stat(buff, &info) == 0)
		return (buff);

	string_pathcpy = malloc(strlen(string_path) + 1);
	string_pathcpy = _strcpy(string_pathcpy, string_path);
	array_main = _divstring(string_pathcpy, ":");

	while (array_main[j] != NULL)
	{
		len_address = _strlen(array_main[j]);
		if (array_main[j][len_address - 1] != '/')
			final_path = _strcatfun(array_main[j], "/");

		final_path = _strcatfun(array_main[j], buff);

		if (stat(final_path, &info) == 0)
		{
			checker = 1;
			break;
		}
		j++;
	}
	if (checker == 0)
		return (NULL);
	free(string_pathcpy);
	free(array_main);
	return (final_path);
}
/**
**_divstring - Auxiliar function to divide a string
*@string_pathcpy: String that is going to be divided
*@separator: Separator that indicates the division point
*Return: Divided array
*/

char **_divstring(char *string_pathcpy, char *separator)
{
	int i = 0, j = 0;
	char *t, **array;

	array = (char **)_calloc(100, sizeof(char *));
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
/**
 *_getenv - Function  get an environment variable
 *@name: Variable of environment to get
 *Return: Value of the variable requested
 */

char *_getenv(const char *name)
{
	int i, j, status;

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
			return (&environ[i][j + 1]);
	}
	return (NULL);
}
