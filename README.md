# DLCS - Digital Logic Circuit Simulator
## Project Description

**DLCS - Digital Logic Circuit Simulator** is a simulator for digital circuits that enables designing and testing various logic gates. The project aims to provide:
  - Efficient management of input and output data.
  - Clean code organization by separating functions into distinct files.
  - Comprehensive error and warning handling.
  - Testing the correctness of the implemented digital logic circuits.

## I/O Structures
### Implemented Features
1. Input and Output Structure:
    - Input data is successfully parsed into appropriate vectors from both input files.
    - Creation of an output file containing the simulation results.
2. Function Segregation:
    - Code is organized across multiple source and header files for better readability and maintainability.
3. Syntax Validation:
    - A dedicated module checks the syntax of input files.
4. Error and Warning Handling:
    - Functions for creating detailed error logs in an `error_file`.
    - Functions for generating warning messages in a `warning_file`.
5. Data Consistency Verification:
    - Functions to verify consistency and integrity of the input files.
6. Command-Line Input Handling (CMD):
    - Functions to process command-line parameters and flags.

## Algorithm
### Implemented Features
- **Logic Gates Implementation:**
  - Seven distinct logic gates (e.g., AND, OR, XOR, NAND, NOR, XNOR, NEG) have been defined and implemented.

## Testing
### Implemented Features
- **Unit and Integration Testing:**
  - Modifying input files and verifying the correctness of results.
  - Logging errors and warnings in dedicated files.

## Installation
1. Clone the repository:
``` cmd
git clone https://github.com/Kosz1212/DLCS.git
```
2. Build and install the program:
``` cmd
make
```
This command cleans up any existing build artifacts or documentation, compiles the project, installs the executable, and generates the documentation via Doxygen.

## Usage
After a successful build and installation, you can run the simulator with:
``` cmd
DLCS <parameters>
```
For example:
``` cmd
DLCS --help
```
If your application supports the `--help` flag, it will display a short description of the available parameters.

## Documentation
Complete project documentation is generated via Doxygen and is located in the `Document/` directory. It includes:

- **HTML:** `Document/html/index.html`

You can open the HTML file in your web browser to explore the code structure and interface.

## Summary
The **DLCS - Digital Logic Circuit Simulator** project has been successfully completed, encompassing all planned functionality, testing, and comprehensive documentation. If you have any questions or encounter any issues, please open a [GitHub issue](https://github.com/Kosz1212/DLCS/issues).

**Thank you for using DLCS - Digital Logic Circuit Simulator!**

### Additional Notes
- If installing the program into a system directory (e.g., `/usr/local/bin`) requires privileges, `make` will prompt you for sudo credentials.
- Ensure that you have installed the necessary tools: a C++ compiler (e.g., g++), **Doxygen** for documentation generation, and **Graphviz** if you want diagram generation in the documentation.
- If you want to automatically open the HTML documentation in your browser, you can uncomment the relevant `xdg-open` lines in the build scripts.

Should you have any questions, feel free to contact me!
