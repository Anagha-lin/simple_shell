#include "shell.h"
/**
 * handle_exit - Handles the "exit" command.
 *
 * @input: The input string to check.
 */
void handle_exit(char *input)
{
	if (_strcmp(input, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * print_env - Handles the "env" by printing the
 * the current environment
 *
 * @input: The input string to check.
 */
void print_env(char *input)
{
	if (_strcmp(input, "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			int len = _strlen(*env);

			write(STDOUT_FILENO, *env, len);
			write(STDOUT_FILENO, "\n", 1);
			env++;
		}
	}
}
