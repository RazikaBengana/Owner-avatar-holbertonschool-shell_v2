#include "shell.h"

/**
 * main - entry point for the shell program
 *
 * this function implements a shell interface that reads commands
 * from the user and executes them;
 *
 * the shell supports basic functionality:
 * - it handles the 'SIGINT' signal to prevent the shell from terminating
 *   when the user presses 'Ctrl+C'
 * - it prompts the user with "$ " if the input is from a terminal
 * - it reads a line of input using the 'func_read' function
 * - it supports the 'exit' command to terminate the shell
 * - it supports the 'env' command to print environment variables using
 *   the 'print_env' function
 * - it splits the input line into arguments using the 'func_split' function
 * - it executes the command specified by the arguments using the 'exec_cmd'
 *   function
 * - it frees all dynamically allocated memory to prevent memory leaks
 *
 * Return: 0, indicating successful termination
 */

int main(void)
{
	int status = 1;
	char *line;
	char **args;

	signal(SIGINT, ctrl_c);

	while (status)
	{
		status = isatty(0);

		if (status == 1)
			write(1, "$ ", 2);

		line = func_read();

		if (line == NULL || (_strcmp(line, "exit") == 0))
		{
			free(line);
			exit(0);
		}
		else if (_strcmp(line, "env") == 0)
		{
			print_env();
			free(line);
			continue;
		}
		args = func_split(line);

		if (args == NULL)
		{
			free_grid(args);
			free(line);
			free(args);
			continue;
		}

		if (line[0] != '\n' || line[1] != '\0')
			status = exec_cmd(args);

		free(line);
		free(args);
	}

	return (0);
}