#include "shell.h"
/**
 * read_input - Read a line of text from standard input.
 *
 * This function reads a line of text from standard input (stdin) and returns
 * it as a dynamically allocated string. It handles end-of-file (Ctrl+D) by
 * returning NULL and freeing the allocated memory.
 *
 * Return: A pointer to the dynamically allocated string containing the input
 *         line, or NULL if end-of-file is reached.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t input_len = 0;

	if (getline(&input, &input_len, stdin) == -1)
	{
		free(input);
		return (NULL);
	}

	input[strcspn(input, "\n")] = '\0';
	return (input);
}

/**
 * get_path - Locate a command in the system's PATH directories
 * @in: The command to search for
 *
 * Return: A pointer to the full path of the command if found, or NULL
 */
char *get_path(char *in)
{
	char *path, *path_cp, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat buf;

	path = "/bin:/sbin:/tmp";
	if (path)
	{
		path_cp = _strdup(path);
		cmd_len = _strlen(in);
		path_token = strtok(path_cp, ":");

		while (path_token != NULL)
		{
			dir_len = _strlen(path_token);
			file_path = malloc(cmd_len + dir_len + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, in);
			_strcat(file_path, "\0");

			if (stat(file_path, &buf) == 0)
			{
				free(path_cp);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_cp);

		if (stat(in, &buf) == 0)
		{
			return (in);
		}
		return (NULL);
	}
	return (NULL);
}


/**
* split_args - Split the command string into arguments.
*
* @command: The command string to split.
* @args: An array to store the arguments.
*
* Return: The number of arguments.
*/
int split_args(char *command, char **args)
{
	char *token = strtok(command, " ");
	int arg_count = 0;

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	return (arg_count);
}

/**
* execute_child - Execute the command in the child process.
*
* @args: The arguments to execute.
* @cmd: The full path of the command.
* @argv0: The name of the calling program for error reporting.
*/
void execute_child(char **args, char *cmd, char *argv0)
{
	if (execve(cmd, args, environ) == -1)
	{
		perror(argv0);
		exit(EXIT_FAILURE);
	}
}

/**
* execute_command - Execute a command using fork and execlp.
*
* @input: The command to execute.
* @argv0: The name of the calling program for error reporting.
*/
void execute_command(char *input, char *argv0)
{
	char *trimmed_input = input + strspn(input, " "), *cmd;
	int input_length = _strlen(trimmed_input);
	pid_t pid = fork();

	if (input_length == 0)
	{
		return;
	}
	if (pid == -1)
	{
		perror(argv0);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[MAX_INPUT_LENGTH], *token = strtok(trimmed_input, " ");
		int arg_count = 0;

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		cmd = get_path(args[0]);
		if (cmd == NULL)
		{
			perror(argv0);
			return;
		}
		execute_child(args, cmd, argv0);
		free(cmd);
	}
	else
	{
		wait(NULL);
	}
}
