CFLAGS += -m32 
LDFLAGS += -m elf_i386
SRC += ./src/.
INCLUDE += ./$(SRC)/include/.
OBJ += ./obj/.
OUT += ./out/.
assemble:
	echo $(OBJ)
	nasm -f aout -o $(OBJ)/start.o $(SRC)/asm/start.asm
# Below: Spot to add gcc sources
compile:
	gcc -Wall -O -fstrength-reduce -m32 -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./$(INCLUDE) -c -o $(OBJ)/main.o $(SRC)/c/main.c

# All files to be linked. All .o files to be added here. If not added, they won't appear in the image
link:
	ld $(LDFLAGS) -T link.ld -o $(OUT)/kernel.bin $(OBJ)/start.o $(OBJ)/main.o
	echo Done!

all: assemble compile link

