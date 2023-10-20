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

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: Pointer to the string to be checked.
 * @accept: Pointer to the string containing the acceptable characters.
 *
 * Return: The number of bytes in the initial segment of s that consist only
 *         of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int count = 0;
	int i, j, fnd;

	for (i = 0; s[i] != '\0'; i++)
	{
		fnd = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				fnd = 1;
				break;
			}
		}
		if (fnd == 0)
		{
			break;
		}
	}
	return (count);
}

/**
 * _strcspn - Calculates the length of a prefix substring in the input string
 * that does not contain any character from the reject set.
 *
 * @s: The input string to search.
 * @reject: The set of characters to reject.
 *
 * Return: The length of the prefix substri.
 */
int _strcspn(const char *s, const char *reject)
{
	const char *p, *r;
	int count = 0;

	for (p = s; *p != '\0'; p++)
	{
		for (r = reject; *r != '\0'; r++)
		{
			if (*p == *r)
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}
