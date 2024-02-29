#include "shell.h"

/**
 * cpy_str2 - Copies n chars of a string into another. Including the '\0'
 * @dest: Pasting location
 * @src: Copied string
 * @n: no of chars to be copied
 *
 * Return: No of bytes Copied (Success)
 */

int cpy_str2(char *dest, char *src, int n)
{
	int i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (i);
}
