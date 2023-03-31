# Define the name of the output file
OUTPUT = bootloader.bin

# Define the names of the source files
SOURCES = main.c

# Define the compiler and linker commands
CC = x86_64-elf-gcc
LD = x86_64-elf-ld

# Define the compiler and linker flags
CFLAGS = -nostdlib -m16 -c
LDFLAGS = -Ttext 0x7c00 --oformat binary

# Define the target rule to build the output file
all: $(OUTPUT)

# Define the rule to build the object file
$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $*.o
	$(LD) $(LDFLAGS) $*.o -o $@

# Define the clean rule to remove generated files
clean:
	rm -f $(OUTPUT) *.o
