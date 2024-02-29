#ifndef SHELL_H
#define SHELL_H


/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <dirent.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>




/* Function Prototypes */
/* Original prototypes */
int shell(int, char **, char **);
int program_path(char *, char **);
int cmd_checker(char *, char **);
int check_string(char *, char **);
/* Peripherals */
int cpy_str(char *, char *);
int cpy_str2(char *, char*, int);
int cmp_str(const char *, const char *, int);
char *cmd_concat(char *, char *);
int len_str(const char *);
int len_arr(char **);
int word_no(char *);
int longer(const char *, const char *);
char **alloc_arr_str(char *, int);
char **alloc_arr_str2(char **, int);
void free_arr_str(char **);
void free_all(char **, ...);
char *get_dir(char **args, char **temp_env);
char *read_each_dir(char *, char *);
void program_path_exec(char *, char **);
int fork_execve(char *cmd_path, char **args);


#endif /* #ifndef SHELL_H */
