#include "shell.h"

/**
**_fork - Executes fork function
*@buff: Buffer that contains command
*@arg: Array to allocate arguments
*
*Return: Always 0
*/

void _fork(char *buff, char *arg)
{
	if (execve(buff, &arg, NULL) == -1)
		perror("Error");
	else
		wait(NULL);
}

/**
**_strtok - Executes strtok function to get PATH
*@buff: Buffer that contains command
*@string_path: Length of command
*
*Return: Always 0
*/

void _strtok(char *buff, char *string_path)
{
	int i = 0;
	char str[100], *s = str, *t = NULL;

	while (string_path[i])
		i++;

	if (strcmp(buff, "PATH") == 0)
	{
		strcpy(str, string_path);
		while ((t = strtok(s, ":")) != NULL)
		{
			printf("%s\n", t);
			s = NULL;
		}
	}
}

/**
**main - Executes simple shell
*
*Return: Always 0
*/

int main(void)
{
	char *buff = NULL;
	size_t len = 0;
	ssize_t return_len = 0;
	int p_id, i = 0;
	char *string_path = getenv("PATH"), *arg[100];

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		return_len = getline(&buff, &len, stdin);
		if (return_len == -1)
			break;

		buff[return_len - 1] = '\0';
		arg[0] = buff;
		arg[1] = NULL;

		if (strcmp("exit", buff) == 0)
			break;

		_strtok(buff, string_path);

		p_id = fork();
		if (p_id == 0)
			_fork(buff, *arg);
	}

	return (0);
}
