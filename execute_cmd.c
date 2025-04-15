#include "shell.h"

/**
* execute_cmd - Executes a command with arguments
* @args: Array of arguments
*/
void execute_cmd(char **args)
{
pid_t pid;
int status;
char *cmd_path = NULL;

if (args[0] == NULL)
return;

/* Built-ins */
if (strcmp(args[0], "exit") == 0)
exit(0);

if (strcmp(args[0], "env") == 0)
{
int i;
for (i = 0; environ[i]; i++)
printf("%s\n", environ[i]);
return;
}

/* Absolute or relative path */
if (access(args[0], X_OK) == 0)
cmd_path = strdup(args[0]);
else
cmd_path = find_path(args[0]);

if (!cmd_path)
{
fprintf(stderr, "./hsh: %s: not found\n", args[0]);
return;
}

pid = fork();
if (pid == 0)
{
if (execve(cmd_path, args, environ) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
perror("fork");
else
waitpid(pid, &status, 0);

free(cmd_path);
}

