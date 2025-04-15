# Simple Shell

## Description

This project is a simple UNIX command line interpreter (shell), built in C, as part of the Holberton School curriculum. It mimics basic functionalities of standard shells such as `sh`, allowing the execution of commands in both interactive and non-interactive modes.

## Features

- Display a prompt (`$ `)
- Wait for user input and execute commands
- Handle commands with arguments
- Use the `PATH` to locate executables
- Built-in commands:
- `exit` - exits the shell
- `env` - prints the environment variables
- Execute commands using `fork`, `execve`, and `wait`
- Handle Ctrl+D (EOF)
- Show error message when command is not found

## Limitations

- Does not support advanced features (pipes `|`, redirection `>`, background `&`, etc.)

## Compilation

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
