#include "shell.h"

/**
**main - Executes simple shell
*Return: Always Zero
*/

int main(void)
{
	char **args, *buff = NULL;
	int status;
	size_t len = 0;
	ssize_t buff_len = 0;
	pid_t p_id;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			printf("$ ");
		buff_len = getline(&buff, &len, stdin); /* Obtaining user's command */
		if (buff_len == -1 || _strcmp("exit\n", buff) == 0) /*Check if its "exit" */
		{
			free(buff);
			break; }
		buff[buff_len - 1] = '\0';
		if (_strcmp("env", buff) == 0) /* Check if its env */
			_env();
		args = _divstring(buff, " "); /* Divide input and allocate it in args */
		args[0] = check_path(args[0]); /* Check if command is valid */
		if (args[0] != NULL)
		{
			p_id = fork(); /* Create new process with fork */
			if (p_id == 0)
			{
				if (execve(args[0], args, environ) == -1) /* Execute valid command */
					perror("Error");
			}
			else
			{
				wait(&status); /* Wait until child process exits */
				if (WIFEXITED(status)) /* True if child process terminates normally */
					status = WEXITSTATUS(status); /* Returns exit status specified */
			}
		}
		else
			perror("Error"); /* Displays error's description if not forked */
		free(args);
	}
	return (0);
}
