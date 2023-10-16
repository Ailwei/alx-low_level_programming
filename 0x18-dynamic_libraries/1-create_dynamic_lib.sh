#!/bin/bash

# Create a list of all .c files in the current directory
c_files=$(find . -maxdepth 1 -name "*.c")

# Compile each .c file into a corresponding .o object file
for file in $c_files; do
    gcc -c -fPIC -o ${file%.c}.o $file
done

# Create the shared library from all the .o files
gcc -shared -o liball.so *.o

# Check if the compilation was successful
if [ $? -eq 0 ]; then
  echo "Dynamic library 'liball.so' created successfully."
else
  echo "Error: Compilation failed."
fi

