#include "shell.h"

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
	int p_id;
	char *arg[100];

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

		p_id = fork();
		if (p_id == 0)
		{
			if (execve(buff, arg, NULL) == -1)
				perror("Error");
		}
		else
			wait(NULL);
	}
	return (0);
}
