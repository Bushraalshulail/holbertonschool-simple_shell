# Simple Shell - hsh

## Description

This project is a simple UNIX command line interpreter (shell), built in C, as part of the Holberton School curriculum.
It mimics basic functionalities of standard shells such as `sh`, allowing the execution of commands in both **interactive** and **non-interactive** modes.

## Features

- Displays a prompt (`$ `)
- Waits for user input and executes commands
- Handles commands with arguments (e.g., `ls -l /tmp`)
- Uses the `PATH` environment variable to locate executables
- Built-in commands:
  - `exit` - exits the shell
  - `env` - prints the current environment variables
- Executes commands using `fork`, `execve`, and `wait`
- Handles `Ctrl+D` (EOF) gracefully
- Displays an error message if a command is not found

## Compilation

To compile the shell, use the following command:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

