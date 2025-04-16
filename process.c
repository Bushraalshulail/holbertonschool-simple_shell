#include "shell.h"

/**
* process_command - processes the user's command
* @line: the command line input
*/
void process_command(char *line)
{
char **args;

args = tokenize(line);
if (args == NULL)
return;

if (_strcmp(args[0], "env") == 0)
print_env();
else
execute_cmd(args);
}

/**
* tokenize - breaks down the command line into arguments
* @line: the input command line
* Return: array of arguments
*/
char **tokenize(char *line)
{
int i = 0;
char **args = malloc(sizeof(char *) * BUFFER_SIZE);
char *token;

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
args[i] = token;
i++;
token = strtok(NULL, " \t\r\n\a");
}
args[i] = NULL;

return args;
}

