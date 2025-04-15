#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
* get_path_from_environ - Extracts the PATH variable from environ
* @env: The environment variables array
*
* Return: The value of the PATH variable or NULL if not found
*/
char *get_path_from_environ(char **env)
{
while (*env)
{
/* Check if the current element starts with "PATH=" */
if (strncmp(*env, "PATH=", 5) == 0)
{
return (*env + 5);  /* Skip "PATH=" and return the path part */
}
env++;
}
return (NULL);  /* Return NULL if PATH is not found */
}

/**
* build_full_path - Constructs the full path from the directory and command
* @dir: The directory
* @command: The command to be executed
*
* Return: A newly allocated string containing the full path
*/
char *build_full_path(char *dir, char *command)
{
size_t len = strlen(dir) + strlen(command) + 2;  /*Calculate required length*/
char *full_path = malloc(len);

if (!full_path)
return (NULL);

/* Build the full path */
snprintf(full_path, len, "%s/%s", dir, command);
return (full_path);
}

/**
* find_path - Finds the full path of a command using PATH
* @command: The command to find
*
* Return: Full path string or NULL if not found
*/
char *find_path(char *command)
{
char **env = environ;/*Use environ instead of getenv toaccess environment var*/
char *path = get_path_from_environ(env);
char *path_copy;
char *dir, *full_path;

if (!path)  /* If PATH is not found in the environment variables */
return (NULL);

path_copy = strdup(path);  /* Duplicate the path string to safely modify it */
if (!path_copy)
return (NULL);

/* Tokenize the path using ':' to get individual directories */
dir = strtok(path_copy, ":");
while (dir)
{
full_path = build_full_path(dir, command);/*Get the full path for the command*/
if (!full_path)
{
free(path_copy);
return (NULL);
}

/* Check if the constructed full path is executable */
if (access(full_path, X_OK) == 0)
{
free(path_copy);  /* Free the duplicated path string */
return (full_path);
}

free(full_path); /*Free the allocated memory if the command is not executable*/
dir = strtok(NULL, ":");  /* Get the next directory in the PATH */
}

free(path_copy);  /* Free the duplicated path string */
return (NULL);  /* Return NULL if no executable file is found */
}

