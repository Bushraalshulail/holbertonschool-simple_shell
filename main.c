#include "main.h"

#define PROMPT "#cisfun$ "

/**
* main - Simple UNIX shell
* Return: 0 on success, 1 on failure
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char *argv[2];

while (1)
{
write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

read = getline(&line, &len, stdin);
if (read == -1) /* Ctrl+D or error */
{
free(line);
write(STDOUT_FILENO, "\n", 1);
break;
}

/* remove newline character */
if (line[read - 1] == '\n')
line[read - 1] = '\0';

if (strlen(line) == 0)
continue;

argv[0] = line;
argv[1] = NULL;

if (fork() == 0)
{
execve(argv[0], argv, environ);
perror("./shell");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}

return (0);
}
