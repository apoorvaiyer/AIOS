CFLAGS += -m32 
LDFLAGS += -m elf_i386
assemble:
	nasm -f aout -o start.o start.asm
# Below: Spot to add gcc sources


# All files to be linked. All .o files to be added here. If not added, they won't appear in the image
link:
	ld $(LDFLAGS) -T link.ld -o kernel.bin start.o
	echo Done!

all: assemble link

