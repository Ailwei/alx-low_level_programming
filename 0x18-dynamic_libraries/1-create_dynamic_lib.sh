#!/bin/bash

# Define the name of the shared library
LIB_NAME="liball.so"

# Compile all .c source files into separate object files
compile_sources() {
  for source_file in *.c; do
    gcc -Wall -Wextra -Werror -pedantic -c -fPIC "$source_file"
  done
}

# Link the object files into a shared library
create_shared_library() {
  gcc -shared -o "$LIB_NAME" *.o
}

# Set LD_LIBRARY_PATH to include the current directory
set_ld_library_path() {
  export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
}

# Clean up object files
clean_up() {
  rm -f *.o
}

# Main script logic
compile_sources
create_shared_library
set_ld_library_path
clean_up

echo "Shared library '$LIB_NAME' created and LD_LIBRARY_PATH updated."

