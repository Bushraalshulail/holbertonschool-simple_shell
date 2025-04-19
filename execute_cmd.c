#include "shell.h"

/**
* prompt_user - Displays the prompt if in interactive mode
*/
void prompt_user(void)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "($) ", 4);
}

/**
* handle_exit - Handles the exit command and frees memory
* @line: The line buffer to free
* @args: The arguments array to free
* @status: The exit status
*/
void handle_exit(char *line, char **args, int status)
{
int exit_status = status;

if (args[1])
exit_status = atoi(args[1]);

free(line);
free(args);
exit(exit_status);
}

/**
* main - Entry point of the shell
* Return: Always 0
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char **args;
int status = 0;

while (1)
{
prompt_user();

read = getline(&line, &len, stdin);
if (read == -1)
{
free(line);
exit(0);
}

args = parse_line(line);
if (args[0] != NULL)
{
if (strcmp(args[0], "exit") == 0)
{
handle_exit(line, args, status);
}
status = execute_cmd(args);
}
free(args);
if (status == 2)
{
free(line);
exit(2);
}
}
return (status);
}
