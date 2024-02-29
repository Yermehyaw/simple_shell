#include "shell.h"


/**
 * read_each_dir - Will open/read the contents of a dir looking for a
 * string/command name passed to it.
 * @ind_path: Path to search
 * @cmd_name: Command name/string
 *
 * Return: The dir the string was found (Success)
 */

char *read_each_dir(char *ind_path, char *cmd_name)
{
	DIR *dir_strm;
	struct dirent *dir_ctnt;
	int lngr;

	dir_strm = opendir(ind_path);
	if (dir_strm == NULL)
		return (NULL);
	dir_ctnt = readdir(dir_strm);
	while (dir_ctnt)
	{
		lngr = longer(cmd_name, dir_ctnt->d_name);
		if (cmp_str(cmd_name, dir_ctnt->d_name, lngr))
		{
			closedir(dir_strm);
			return (ind_path);
		}
		dir_ctnt = readdir(dir_strm);
	}
	closedir(dir_strm);
	return (NULL); /* Name not found in dir */
}
