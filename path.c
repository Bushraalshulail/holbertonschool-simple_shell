#include "shell.h"

/**
* find_path - Searches for the full path of a command
* @command: Command name
*
* Return: Full path string if found, or NULL
*/
char *find_path(char *command, char **env)

char *find_path(char *command)
{
char *path = getenv("PATH");
char *token, full_path[BUFFER_SIZE];
struct stat st;

if (command[0] == '/' || command[0] == '.')
{
if (stat(command, &st) == 0)
return (strdup(command));
return (NULL);
}

token = strtok(path, ":");
while (token != NULL)
{
snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
if (stat(full_path, &st) == 0)
return (strdup(full_path));
token = strtok(NULL, ":");
}

return (NULL);
}

