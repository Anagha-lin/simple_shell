#include "shell.h"
/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return:
 * - 0 if the strings are equal.
 * - a negative value if s1 is less than s2.
 * - a positive value if s1 is greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strcpy - Copying a string
 * @dest: Destination input
 * @src: Source Value
 * Return: The poiner to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (dest);
}

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 * @s: The string to duplicate.
 * Return: Pointer to the duplicated string, or NULL if it fails.
 */
char *_strdup(char *s)
{
	size_t len = _strlen(s);
	char *copy = (char *)malloc(len + 1);

	if (s == NULL)
	{
		return (NULL);
	}

	if (copy == NULL)
	{
		return (NULL);
	}
	_strcpy(copy, s);

	return (copy);
}
