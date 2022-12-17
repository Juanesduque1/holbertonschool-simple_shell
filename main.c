#include "shell.h"

/**
**_strtok - Executes strtok function to get PATH
*@buff: Buffer that contains command
*@string_path: Length of command
*
*Return: Always 0
*/

char **_strtok(char *string_path)
{
	int i = 0, j = 0;
	char *t;
	char **array;

	array = (char **)malloc(sizeof(char *) * 1024);
	while (string_path[i])
		i++;
	while ((t = strtok(string_path, ":")) != NULL)
	{
		if (t == NULL)
		{
			break;
		}
		array[j] = t;
		string_path = NULL;
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
	char *buff = NULL, **array_main, *slash = "/";
	size_t len = 0;
	ssize_t buff_len = 0;
	int p_id, j = 0, len_address;
	char *string_path = getenv("PATH"), *arg[100];

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
		if (strcmp(buff, "PATH") == 0)
			array_main = _strtok(string_path);
		printf("%s\n%s\n%s\n", array_main[10], array_main[3], array_main[13]);
		/**while (array_main[j] != NULL)
		{
			len_address = _strlen(array_main[j]);
			if (_strcmp(array_main[j][len_address - 1], slash) != 0)
			{
				array_main[j][len_address] = slash;
			}
			array_main[j][len_address + 1] = buff;
			array_main[j][len_address + 2] = "\0";
			j++;
		}**/
	}
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
