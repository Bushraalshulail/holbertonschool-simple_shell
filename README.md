# Simple Shell - `hsh`

## 📚 Description

This project is a **simple UNIX command line interpreter (shell)** developed in C as part of the Holberton School curriculum.  
It replicates basic features of standard shells like `sh`, allowing the execution of commands in **interactive** and **non-interactive** modes.

---

## 🚀 Features

- 💬 Displays a prompt (`$ `)
- ⌨️ Accepts and parses user input
- ⚙️ Executes commands with arguments (e.g., `ls -l /tmp`)
- 🌐 Resolves command paths using the `PATH` environment variable
- 🧠 Built-in commands:
  - `exit` – exits the shell
  - `env` – displays current environment variables
- 👶 Uses `fork`, `execve`, and `wait` to run processes
- 🛑 Handles `Ctrl+D` (EOF) gracefully
- 🚫 Shows an error message if command is not found

---
## 🛠️ Compilation

To compile the program, run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
