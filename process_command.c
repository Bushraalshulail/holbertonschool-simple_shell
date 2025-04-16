#include "shell.h"

/**
* process_command - Processes a command entered by the user.
* @line: The line entered by the user.
* @env: The environment variables.
*
* Return: 1 if successful, otherwise 0.
*/
int process_command(char *line, char **env)
{
char **args;
char *full_path;
int status;

args = split_line(line);
if (args[0] == NULL)
return (1);

if (strcmp(args[0], "exit") == 0)
return (0);

full_path = find_path(args[0], env);
if (full_path == NULL)
{
print_error(args[0]);
return (1);
}

status = execute(args, env);
free(full_path);
return (status);
}
