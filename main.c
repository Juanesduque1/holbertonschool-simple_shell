#include "shell.h"

/**
**main - Executes simple shell
*Return: Always Zero
*/

int main(void)
{
	char **args, *buff = NULL;
	int status = 0, i = 0, spaces = 1;
	size_t len = 0;
	ssize_t buff_len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) != 0)
			printf("$ ");
		buff_len = getline(&buff, &len, stdin);	/* Obtaining user's command */
		if (buff_len == -1 || _strcmp("exit\n", buff) == 0) /*Check if its "exit" */
		{
			free(buff);
			break; }
		buff[buff_len - 1] = '\0';
		if (_strcmp("env", buff) == 0) /* Check if its env */
		{
			_env();
			continue; }
		for (i = 0; buff[i] != '\0'; i++) /* Check if input has spaces */
		{
			if (buff[i] != ' ')
			{
				spaces = 0;
				break; }
		}
		if (spaces == 1)
		{
			status = 0;
			continue; }
		args = _divstring(buff, " ");  /* Divide input and allocate it in args */
		args[0] = check_path(args[0]); /* Check if command is valid */

		if (args[0] != NULL)
			status = fork_function(args); /* Executes fork and execve function */
		else
			perror("Error"); /* Displays error's description if not forked */
		free(args);
	}
	return (status);
}
