# Compiler settings - change these if not using gcc or if additional flags are needed
CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -g

# Default target
all: hsh

# Compile the program with all .c files in the directory
hsh: *.c
	$(CC) $(CFLAGS) $^ -o $@

# Target to run the compiled program
run:
	./hsh

# Clean the build directory
clean:
	rm hsh
