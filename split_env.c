#include "shell.h"

/**
 * split_env - program that splits a PATH string into an array of directory paths
 *
 * this function takes a 'path' string containing directories separated by colons (:),
 * such as the PATH environment variable in Unix-like systems, and splits it into
 * an array of strings, each representing a directory path;
 * the function uses the `strtok` function to tokenize the input string by colons;
 * memory for the array of directory paths is dynamically allocated;
 * if memory allocation fails, the function prints an error message and exits
 * the program
 *
 * @path: the PATH string to be split, usually obtained from an environment variable
 *
 * Return: a pointer to an array of strings, where each string is a directory path
 */

char **split_env(char *path)
{
	int size = 1024;
	int i = 0;
	char **tab_path = malloc(size * sizeof(char *));
	char *token;

	if (tab_path == NULL)
	{
		perror("Error : malloc");
		exit(1);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		tab_path[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	tab_path[i] = NULL;

	return (tab_path);
}
