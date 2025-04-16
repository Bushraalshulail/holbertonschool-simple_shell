#include "shell.h"

/**
* execute_cmd - executes a command
* @args: array of arguments
*/
void execute_cmd(char **args)
{
char *full_path;
pid_t pid;
int status;

full_path = find_path(args[0], environ);

if (!full_path)
{
print_error(args[0]);
return;
}

pid = fork();
if (pid == 0)
{
if (execve(full_path, args, environ) == -1)
{
print_error(args[0]);
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("fork failed");
}
else
{
wait(&status);
}
}

