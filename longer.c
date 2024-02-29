#include "shell.h"


/**
 * longer - Returns the length of the longer string including null byte
 * @str1: First string
 * @str2: Second string
 *
 * Description: longer() functions primarily in comp_str() where it helps
 * ensureboth strings are fully compared. Thus the null byte is added
 * to ensure every char in both strinhs are fully compared with each other.
 *
 * Return: Length of the longer string (Succes)
 */

int longer(const char *str1, const char *str2)
{
	int i, j;

	if (str1 == NULL && str2 == NULL)
		return (1); /* longer() is to be used in cmp_str() */
	if (str1 == NULL)
		return (len_str(str2) + 1); /* +1 for the removed null byte */
	if (str2 == NULL)
		return (len_str(str1) + 1);
	for (i = 0; str1[i] != '\0'; ++i) /* Get their lengths */
		;
	for (j = 0; str2[j] != '\0'; ++j)
		;
	if (i < j)
		return (++j); /* Adding null byte */
	else
		return (++i);
	return (++i); /* or ++j, i and j are equal */

}
