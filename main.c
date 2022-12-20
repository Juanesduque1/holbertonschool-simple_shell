#include "shell.h"

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

/**
**check_array - Checks if array's address exists
*@array_main: Array of addresses
*@buff: Buffer that contains command
*
*Return: Always 0
*/

char *check_array(char **array_main, char *buff)
{
	char *final_path;
	int j = 0, len_address;
	struct stat info;

	while (array_main[j] != NULL)
	{
		len_address = strlen(array_main[j]);
		if (array_main[j][len_address - 1] != '/')
			final_path = _strcat(array_main[j], "/");

		final_path = _strcat(array_main[j], buff);

		if (stat(final_path, &info) == 0)
			break;

		j++;
	}

	return (final_path);
}

/**
**_strtok - Executes strtok function to get PATH
*@buff: Buffer that contains command
*@string_path: Length of command
*
*Return: Always 0
*/

char **_divstring(char *string_pathcpy)
{
	int i = 0, j = 0;
	char *t;
	char **array;

	array = (char **)malloc(sizeof(char *) * 1024);
	while (string_pathcpy[i])
		i++;
	while ((t = strtok(string_pathcpy, ":")) != NULL)
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
*Return: Always 0
*/

int main(void)
{
	char *buff = NULL, **array_main, *final_path;
	size_t len = 0;
	ssize_t buff_len = 0;
	int p_id, j = 0, len_address;
	char *string_path = getenv("PATH"), *arg[100], *string_pathcpy;

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		buff_len = getline(&buff, &len, stdin);
		if (buff_len == -1)
			break;

		buff[buff_len - 1] = '\0';
		arg[0] = buff;
		arg[1] = NULL;

		if (strcmp("exit", buff) == 0)
			break;
		
		string_pathcpy = strcpy(string_pathcpy, string_path);

		array_main = _divstring(string_pathcpy);
		printf("%s\n%s\n", array_main[0], array_main[5]);

		final_path = check_array(array_main, buff);

		buff = final_path;
		printf("%s\n%s\n", buff, final_path);
		p_id = fork();
		if (p_id == 0)
		{
			if (execve(buff, arg, NULL) == -1)
				perror("Error");
		}
		else
			wait(NULL);

		return (0);
	}
}
