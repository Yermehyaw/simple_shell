#include "shell.h"


/**
 * word_no - Returns the no of words  corresponding to the no of spaces in
 * a string (To be used to malloc() args in program_path())
 * @str: String
 *
 * Return: No of words (Success)
 */

int word_no(char *str)
{
	int i, space;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; ++i)
	{
		if (str[i] == ' ')
			++space;
	}
	return (space + 1); /* 2 spaces equals 3 words */
}
