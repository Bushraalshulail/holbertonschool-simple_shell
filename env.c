#include "shell.h"

/**
* print_env - prints the current environment variables
*/
void print_env(void)
{
int i;

for (i = 0; environ[i] != NULL; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
}

