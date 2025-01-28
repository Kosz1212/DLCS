#!/bin/bash

# Script for automating program compilation, installation, and documentation generation using Doxygen.

# Function to display messages in color
function echo_success {
    echo -e "\e[32m$1\e[0m"
}

function echo_info {
    echo -e "\e[34m$1\e[0m"
}

function echo_error {
    echo -e "\e[31m$1\e[0m"
}

# Set paths
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"  # Directory where the script is located
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"                      # Main project directory
SRC_DIR="$PROJECT_DIR/Src"                                   # Source files directory
CONFIG_DIR="$SCRIPT_DIR"                                    # Config directory
DOXYFILE="$CONFIG_DIR/Doxyfile"                             # Path to Doxyfile
DOC_DIR="$PROJECT_DIR/Document"                              # Output directory for documentation
EXECUTABLE="$SRC_DIR/DLCS"                                    # Path to the executable file
INSTALL_DIR="/usr/local/bin"                                 # Installation directory (requires sudo)

# Compile the program
echo_info "Starting program compilation..."

cd "$SRC_DIR" || { echo_error "Error: Failed to change directory to '$SRC_DIR'."; exit 1; }

# Run make
make
MAKE_STATUS=$?

if [ $MAKE_STATUS -ne 0 ]; then
    echo_error "Error: Program compilation failed."
    exit $MAKE_STATUS
fi

echo_success "Program compilation completed successfully."

# Install the program
echo_info "Installing the program to '$INSTALL_DIR'..."

if [ -w "$INSTALL_DIR" ]; then
    cp "$EXECUTABLE" "$INSTALL_DIR/DLCS"
else
    sudo cp "$EXECUTABLE" "$INSTALL_DIR/DLCS"
fi

echo_success "The program has been installed as 'DLCS' in '$INSTALL_DIR'."

# Generate documentation using Doxygen
echo_info "Starting documentation generation using Doxygen..."

doxygen "$DOXYFILE"
DOXYGEN_STATUS=$?

if [ $DOXYGEN_STATUS -ne 0 ]; then
    echo_error "Error: Documentation generation using Doxygen failed."
    exit $DOXYGEN_STATUS
fi

echo_success "Documentation generation completed successfully."

echo_success "Build and installation process completed successfully."
echo_info "Documentation is available in the '$DOC_DIR' directory."
echo_info "The program can be run using: DLCS <parameters>"

exit 0