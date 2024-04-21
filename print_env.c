#include "shell.h"

/**
 * print_env - program that prints all environment variables
 * to the standard output
 *
 * this function iterates through the 'environ' array, which contains
 * all the environment variables available in the current execution
 * environment;
 * for each variable, it calculates the string length using '_strlen',
 * then outputs the variable using 'write' to the standard output
 * (file descriptor 1);
 * each variable is printed on a new line
 *
 * Return: nothing (void)
 */

void print_env(void)
{
	int i = 0;
	int length = 0;

	for (i = 0; environ[i]; i++)
	{
		length = _strlen(environ[i]);
		write(1, environ[i], length);
		write(1, "\n", 1);
	}
}
