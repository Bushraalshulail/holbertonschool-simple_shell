#include "shell.h"

/**
* find_path - Finds the full path of a command.
* @command: The command to find the path for.
* @env: The environment variables.
*
* Return: The full path of the command if found, otherwise NULL.
*/
char *find_path(char *command, char **env)
{
char *path = getenv("PATH");
char *token;
char full_path[1024];

token = strtok(path, ":");
while (token != NULL)
{
snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
if (access(full_path, F_OK) == 0)
return strdup(full_path);
token = strtok(NULL, ":");
}
return NULL;
}

