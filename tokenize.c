#include "shell.h"

/**
* tokenize - Tokenizes a line into arguments.
* @line: The line to tokenize.
*
* Return: An array of strings containing the tokens.
*/
char **tokenize(char *line)
{
int bufsize = 64, i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
perror("allocation error");
exit(1);
}

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[i] = token;
i++;

if (i >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
perror("allocation error");
exit(1);
}
}

token = strtok(NULL, " \t\r\n\a");
}
tokens[i] = NULL;
return tokens;
}

