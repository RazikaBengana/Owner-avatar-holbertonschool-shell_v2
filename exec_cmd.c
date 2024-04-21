#include "shell.h"

/**
 * exec_cmd - program that executes a command using a new child process
 *
 * this function attempts to execute a command specified by the `args` array;
 * it first forks a new process;
 * if the fork is successful, it checks whether the command is specified with
 * an absolute path (`/`) or a relative path (`.`);
 * if neither, it attempts to resolve the command's path using `get_path`;
 * if the command or the arguments are not valid, it handles errors appropriately;
 * after setting up the command, it uses `execve` to execute the command
 * in the child process;
 * the parent process waits for the command to complete and returns the exit status
 *
 * @args: a null-terminated array of strings representing the command
 *        and its arguments;
 *        args[0] contains the command, followed by any additional arguments
 *
 * Return: 1 on successful execution of the command by the parent process,
 *         or 0 if an execution error occurs in the child process
 */

int exec_cmd(char **args)
{
	pid_t my_pid;
	char *getcmd = args[0];
	int status;

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("Error : fork");
	}

	if (my_pid == 0)
	{

		if (getcmd[0] == '/' || getcmd[0] == '.')
		{
			getcmd = args[0];
		}
		else
		{
			getcmd = get_path(args[0]);
		}
		if (args[0] == NULL)
		{
			perror("Error : no argument");
		}
		if (getcmd == NULL)
		{
			free(getcmd);
			perror("Error : execve");
			return (0);
		}
		else
        	{
            		execve(getcmd, args, environ);
        	}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
