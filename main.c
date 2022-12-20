#include "shell.h"

/**
**_strcatfun - Concatenate two strings
*@dest: Variable of the destination
*@src: Variable of the string
*
*Return: Always 0
*/

char *_strcatfun(char *dest, char *str)
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

/**
**check_array - Checks if array's address exists
*@array_main: Array of addresses
*@buff: Buffer that contains command
*Return: Always 0
*/

char *check_array(char *buff)
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

	array = (char **)malloc(sizeof(char *) * 1024);
	while (string_pathcpy[i])
		i++;
	while ((t = strtok(string_pathcpy, separator)) != NULL)
	{
		if (t == NULL)
			break;

		array[j] = t;
		string_pathcpy = NULL;
		j++;
	}
	return (&(*array));
}

/**
**main - Executes simple shell
*
*Return: integer
*/

int main(void)
{
	char *buff = NULL, *final_path;
	size_t len = 0;
	ssize_t buff_len = 0;
	pid_t p_id;
	int j = 0, len_addres, n;
	int status;
	char *string_path = getenv("PATH"), **args, *string_pathcpy;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			printf("$ ");

		buff_len = getline(&buff, &len, stdin);
		if (buff_len == -1)
			break;

		buff[buff_len - 1] = '\0';

		if (strcmp("exit", buff) == 0)
			break;

		args = _divstring(buff, " ");

		final_path = check_array(args[0]);

		p_id = fork();
		if (p_id == 0)
		{
			if (execve(final_path, args, NULL) == -1)
			{
				exit(-1);
			}
			status = 0;
			exit(0);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				status = WEXITSTATUS(status);
			}
		}
		while (args[n])
		{
			free(args[n]);
			n++;
		}
		free(args);
	}
	free(string_path);
	free(string_pathcpy);
	return (0);
}
