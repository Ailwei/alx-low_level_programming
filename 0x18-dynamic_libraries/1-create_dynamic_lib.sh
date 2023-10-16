#!/bin/bash

# Compile and create a dynamic library from all .c files in the current directory
gcc -shared -o liball.so *.c

# Check if the compilation was successful
if [ $? -eq 0 ]; then
  echo "Dynamic library 'liball.so' created successfully."
else
  echo "Error: Compilation failed."
fi

