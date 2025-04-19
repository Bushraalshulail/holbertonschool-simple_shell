#!/bin/bash

# Example checker.bash script

# Check if valgrind and ltrace are installed
if ! command -v valgrind &>/dev/null || ! command -v ltrace &>/dev/null; then
    echo "Valgrind or ltrace not found, please install them."
    exit 1
fi

# Execute the program and check with valgrind and ltrace
valgrind --leak-check=full --error-exitcode=1 $1
if [ $? -eq 0 ]; then
    echo "Valgrind passed."
else
    echo "Valgrind errors detected."
fi

ltrace -e malloc,free $1
if [ $? -eq 0 ]; then
    echo "ltrace executed successfully."
else
    echo "ltrace encountered an error."
fi

