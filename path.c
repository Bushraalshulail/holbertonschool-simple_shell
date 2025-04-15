#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
* find_path - Finds the full path of a command using PATH
* @command: The command to find
*
* Return: Full path string or NULL if not found
*/
char *find_path(char *command)
{
char *path = getenv("PATH");
char *path_copy = strdup(path);
char *dir, *full_path;
size_t len;

if (!path_copy)
return (NULL);

dir = strtok(path_copy, ":");
while (dir)
{
len = strlen(dir) + strlen(command) + 2;
full_path = malloc(len);
if (!full_path)
{
free(path_copy);
return (NULL);
}

snprintf(full_path, len, "%s/%s", dir, command);
if (access(full_path, X_OK) == 0)
{
free(path_copy);
return (full_path);
}
free(full_path);
dir = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}

