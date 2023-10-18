#include "shell.h"

/**
 * Function to exit the shell.
 * @info: A structure that may contain exit arguments.
 * Returns: Exits with the given exit status (0) if info->argv[0] != "exit".
 */
int _myexit(info_t *info)
{
    int exitStatus;

    if (info->argv[1]) /* Check for the presence of an exit argument */
    {
        exitStatus = _erratoi(info->argv[1]);
        if (exitStatus == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            _eputs(info->argv[1]);
            _eputchar('\n');
            return (1);
        }
        info->err_num = _erratoi(info->argv[1]);
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}

/**
 * Function to change the current directory of the process.
 * @info: A structure that may contain potential arguments.
 * Returns: Always returns 0.
 */
int _mycd(info_t *info)
{
    char *currentDirectory, *requestedDirectory, buffer[1024];
    int chdirResult;

    currentDirectory = getcwd(buffer, 1024);
    if (!currentDirectory)
        _puts("TODO: Handle getcwd failure here\n");

    if (!info->argv[1])
    {
        requestedDirectory = _getenv(info, "HOME=");
        if (!requestedDirectory)
            chdirResult = /* TODO: Define behavior for this case */ chdir((requestedDirectory = _getenv(info, "PWD=")) ? requestedDirectory : "/");
        else
            chdirResult = chdir(requestedDirectory);
    }
    else if (_strcmp(info->argv[1], "-") == 0)
    {
        if (!_getenv(info, "OLDPWD="))
        {
            _puts(currentDirectory);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD="));
        _putchar('\n');
        chdirResult = /* TODO: Define behavior for this case */ chdir((requestedDirectory = _getenv(info, "OLDPWD=")) ? requestedDirectory : "/");
    }
    else
        chdirResult = chdir(info->argv[1]);

    if (chdirResult == -1)
    {
        print_error(info, "Can't change to directory: ");
        _eputs(info->argv[1]);
        _eputchar('\n');
    }
    else
    {
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}
/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /*temp att_unused workaround */
	return (0);
}

