#include "shell.h"


/**
 * get_dir - aka Dze Beast... Finds PATH in an efitable copy of the environ
 * variables, access its variables  and locate a command in its dirs.
 * May the Lord help you as you attempt to understand get_dir() ;)
 * @args: Command name and arguments
 * @temp_env: Copy of environ variables
 *
 * Return: The directory the command was found. A string (Success)
 */

char *get_dir(char **args, char **temp_env)
{
	char *ind_path, *vrb, *dir_found;
	int i;

	ind_path = "Sentinel value";
	/*Tokenize the copy of emviron */
	dir_found = NULL;
	vrb = NULL;
	i = 0;
	while (temp_env[i])
	{
		vrb = strtok(temp_env[i], "=");
		if (cmp_str("PATH", vrb, 5))
			break; /* PATH is found */
		++i; /* Location of patg in environ */
	}
	if (vrb == NULL) /* PATH not found */
		return (NULL);
	/* Get dirs in PATH */
	while (ind_path) /*Single out each dir in PATH */
	{
		ind_path = strtok(NULL, ":"); /*PATH was where the loop broke*/
		if (ind_path == NULL) /* No more dirs/ no dirs at all */
			break;
		/* Open and read each dir */
		dir_found = read_each_dir(ind_path, args[0]);
		if (dir_found != NULL) /* Command found in ind_path */
			break;
	}
	return (dir_found);
}
