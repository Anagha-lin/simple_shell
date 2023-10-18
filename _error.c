#include "shell.h"

/**
 * _eputs - Function to print a string to standard error.
 * @str: The string to be printed.
 * Returns: Nothing.
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Function to write a character to standard error.
 * @c: The character to print.
 * Returns: 1 on success. -1 on error with errno set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - * Function to write a character to a specified file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 * Returns: 1 on success. -1 on error with errno set appropriately.
 */
int _putfd(char c, int fd)
{
    static int i;
    static char buf[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(fd, buf, i);
        i = 0;
    }
    if (c != BUF_FLUSH)
        buf[i++] = c;
    return (1);
}


/**
 * _putsfd -  * Function to print a string to a specified file descriptor.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 * Returns: The number of characters written.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
