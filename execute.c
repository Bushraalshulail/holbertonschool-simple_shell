#include "shell.h"
#include <unistd.h>
#include <stdio.h>

/**
* execute - Executes a command using execve
* @args: Arguments passed (command + args)
* @env: Environment variables
* Return: status code
*/
int execute(char **args, char **env)
{
pid_t pid;
int status;

if (args == NULL || args[0] == NULL)
return (1);

pid = fork();
if (pid == -1)
{
perror("fork");
return (1);
}
else if (pid == 0)
{
execve(args[0], args, env);
perror(args[0]);
_exit(127);
}
else
{
waitpid(pid, &status, 0);
}

return (WEXITSTATUS(status));
}

