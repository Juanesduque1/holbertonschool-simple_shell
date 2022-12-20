#include "shell.h"

/**
**search_path - function search PATH
*@buff: Buffer that contains command
*@string_path: Length of command
*Return: char pointer
*/

char *search_path(char *string_path, char *buff)
{
	char *array_main, *token, *dir;
	char *slash = "/";
	struct stat st;

	array_main = strtok(string_path, ":");
	while (array_main != NULL)
	{
		if (stat(array_main, &st) == 0)
		{
			printf("encontre");
			return token;
		}
		array_main = strtok(NULL, ":");
	}

	array_main = strtok(string_path, ":");
	token = _strcat(array_main, slash, buff);

	return token;
}