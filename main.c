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
	ssize_t return_len;

	while (1)
	{
		printf("$ ");
		return_len = getline(&buff, &len, stdin);
		buff[return_len - 1] = '\0';
		printf(" %s\n", buff);
		if (strcmp("exit", buff) == 0)
			break;
	}
	return (0);
}
