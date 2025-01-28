#!/bin/bash

# Script for cleaning compilation files and documentation

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
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
SRC_DIR="$PROJECT_DIR/Src"
DOC_DIR="$PROJECT_DIR/Document"

# Clean compilation files
echo_info "Cleaning compilation files in directory '$SRC_DIR'..."
cd "$SRC_DIR" || { echo_error "Error: Failed to change directory to '$SRC_DIR'."; exit 1; }
make clean || echo_info "Target 'clean' not found in Makefile, skipping."

# Clean documentation
echo_info "Cleaning documentation in directory '$DOC_DIR'..."
rm -rf "$DOC_DIR"/*

# Return to Config directory
cd "$SCRIPT_DIR" || { echo_error "Error: Failed to change directory to '$SCRIPT_DIR'."; exit 1; }

echo_success "Cleaning completed successfully."
exit 0