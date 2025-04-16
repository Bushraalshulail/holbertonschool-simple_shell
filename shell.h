#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* environ declaration */
extern char **environ;

/* Shell functions */
char *read_line(void);
char **split_line(char *line);
int execute(char **args, char **env);
char *find_path(char *command, char **env);
void print_env(void);
void print_error(char *command);
char **tokenize(char *line);

/* String utils */
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* Memory management */
void free_args(char **args);

#endif /* SHELL_H */

