#!/bin/bash

# Define the URL for the shared library
LIB_URL="https://raw.githubusercontent.com/monoprosito/holbertonschool-low_level_programming/master/0x18-dynamic_libraries/libgiga.so"

# Destination directory for the shared library
DEST_DIR="../"

# Name of the shared library
LIB_NAME="libgiga.so"

# Download the shared library
wget -P "$DEST_DIR" "$LIB_URL"

# Check if the download was successful
if [ $? -eq 0 ]; then
  echo "Downloaded $LIB_NAME successfully."
  # Set LD_PRELOAD to the full path of the shared library
  export LD_PRELOAD="$PWD/$DEST_DIR$LIB_NAME"
  echo "LD_PRELOAD is set to $LD_PRELOAD"
else
  echo "Error: Failed to download $LIB_NAME."
fi

