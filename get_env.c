#include "shell.h"

/**
 * get_env - program that retrieves the value of an environment variable
 *
 * this function searches through the environment variable array 'environ'
 * to find the variable specified by 'getcmd';
 * it compares each environment variable's name with 'getcmd';
 * if a match is found, it returns the value of the environment variable
 *
 * @getcmd: the name of the environment variable to retrieve
 *
 * Return: a pointer to the value of the environment variable,
 *         or NULL if not found
 */

char *get_env(char *getcmd)
{
	int i, size;

	size = _strlen(getcmd);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], getcmd, size) == 0)
			return (environ[i] + size + 1);
	}
	return (NULL);
}
