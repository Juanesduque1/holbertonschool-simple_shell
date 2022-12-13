#include "shell.h"

/**
**main - Executes simple shell
*
*Return: Always 0
*/

int main()
{
	while(1)
	{
		char command[100];
		printf("$ ");
		scanf(" %99[^\n]", command);
		if (!strcmp("exit", command))
		{
			break;
		}

		printf("%s\n", command);
	}
	return (0);
}
