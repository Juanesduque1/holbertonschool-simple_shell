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
	int p_id, i = 0;
	char *arg[100], *string_path = getenv("PATH");
	char str[100], *s = str, *t = NULL;

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

		while (string_path[i])
		{
			i++;
		}

		if (strcmp(buff, "PATH") == 0)
		{

			strcpy(str, string_path);
			while ((t = strtok(s, ":")) != NULL)
			{
				printf("%s\n", t);
				s = NULL;
			}
		}
		/*funcion_validar_ruta(ruta + comando )
	else
	print eror*/
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
