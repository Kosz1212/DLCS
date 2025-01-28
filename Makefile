# Path to scripts
BUILD_SCRIPT = Config/build.sh
CLEAN_SCRIPT = Config/clean.sh

# Default target: clean first, then build the project
all: clean build

# Build target: invokes the build.sh script
build:
	bash $(BUILD_SCRIPT)

# Clean target: invokes the clean.sh script
clean:
	bash $(CLEAN_SCRIPT)