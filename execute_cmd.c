#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
* execute_cmd - Executes a command with arguments
* @args: The arguments to execute
* @env: The environment variables
*
* Return: status code of the command executed
*/
int execute_cmd(char **args, char **env)
{
pid_t pid;
int status;

pid = fork();
if (pid == -1)
{
perror("fork");
return (1);
}
if (pid == 0)
{
if (execve(args[0], args, env) == -1)
{
perror(args[0]);
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
if (WIFEXITED(status))
{
return (WEXITSTATUS(status));
}
}
return (0);
}

