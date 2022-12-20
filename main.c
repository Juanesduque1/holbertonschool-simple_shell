#include "shell.h"

/**
**main - Executes simple shell
*@argc: Quantity of elements that gets the function
*@argv: Arguments of the function
*@env: Environment variable*
*Return: Always Zero
*/

int main(int argc, char **argv, char **env)
{
	char **args, *buff = NULL, *final_path;
	int n, status;
	size_t len = 0;
	ssize_t buff_len = 0;
	pid_t p_id;

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
		args[0] = check_path(args[0]);

		p_id = fork();
		if (p_id == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error");
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
		}
	}
	return (0);
}
