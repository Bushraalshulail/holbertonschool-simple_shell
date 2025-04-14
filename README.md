# Simple Shell

## Description
This project implements a simple UNIX command line interpreter (shell). The shell reads commands from the user, executes them using the `execve` system call, and handles errors if the command is not found. It supports a basic prompt and handles the "end of file" condition (Ctrl+D).

## Features
- Display a prompt (`#cisfun$ `).
- Wait for user input and execute commands.
- Handle errors when commands are not found.
- Process the "end of file" condition (Ctrl+D).
- Does not handle advanced shell features like pipes, semicolons, or arguments.

## Compilation
The shell is compiled with:
