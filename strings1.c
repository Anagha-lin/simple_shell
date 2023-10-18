#include "shell.h"
/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the string containing the bytes to search for.
 *
 * Return: A pointer to the first occurrence of a byte in s that matches one
 *         of the bytes in accept, or NULL if no such byte is found.
 */
char *_strpbrk(char *s, const char *accept)
{
	while (*s != '\0')
	{
		const char *c = accept;

		while (*c != '\0')
		{
			if (*s == *c)
			{
				return (s);
			}
			c++;
		}
		s++;
	}
	return (NULL);
}

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @s: Pointer to the string.
 * @c: Character to be located.
 *
 * Return: Pointer to the first occurrence of the character c in the string s,
 *         or NULL if the character is not found.
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return ('\0');
}

/**
 * _strtok - Tokenize a string using specified delimiters
 * @str: The string to be tokenized
 * @delimiters: A string containing delimiters
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *rest;
	char *token = rest;
	char *delimiter_position = _strpbrk(rest, delimiters);

	if (str != NULL)
	{
		rest = str;
	}

	if (rest == NULL || *rest == '\0')
	{
		return (NULL);
	}

	while (*rest != '\0' && _strchr(delimiters, *rest) != NULL)
	{
		rest++;
	}

	if (*rest == '\0')
	{
		return (NULL);
	}

	if (delimiter_position != NULL)
	{
		*delimiter_position = '\0';
		rest = delimiter_position + 1;
	}
	else
	{
		rest = NULL;
	}
	return (token);
}

/**
* _strlen - function that calculates the length of a string
* @str: length is to be calculated
* Return: length of the string
*/
int _strlen(char *str)
{
	char *len = str;

	while (*len != '\0')
	{
		len++;
	}
	return (len - str);
}
/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}
