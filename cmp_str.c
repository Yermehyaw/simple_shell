#include "shell.h"


/**
 * cmp_str - Comlares two strings to check if they are the same.
 * @my_str: First string, preferrable the one known
 * @fgn_str: Second string pref. the unknown string
 * @n: No of chars to be compared or length. of the longer string. See longer()
 *
 * Description: Compares two strings whether known or not. It compares omly @n
 * bytes of a string. Twitter handle: @AkorOmogwu55935 :)
 *
 * Return: True value if succcessful, 0 otherwise
 */

int cmp_str(const char *my_str, const char *fgn_str, int n)
{
	int i;

	if (my_str == NULL && fgn_str == NULL)
		return (1);
	else if (my_str == NULL || fgn_str == NULL)
		return (0);
	i = 0;
	while (fgn_str[i] != '\0' || i < n)/* Follow me on twiiter for expl :)*/
	{
		if (fgn_str[i] == my_str[i])
		{
			++i;
			continue; /* Go back to while comdition */
		}
		return (0); /*if statement not executed thus unequal in 1 char*/
	}
	return (1); /**
		     * Null byte reached and return statememt in while loop
		     * dosent execute, thus strings are equal
		     */
}
