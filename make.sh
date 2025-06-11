
    i386-elf-gcc -c -g -Os -march=i686 -ffreestanding -Wall -Werror boot.c -o boot.o
    i386-elf-gcc -c -g -Os -march=i686 -ffreestanding -Wall -Werror init.c -o init.o
    i386-elf-gcc -c -g -Os -march=i686 -ffreestanding -Wall -Werror print.c -o print.o
    i386-elf-gcc -c -g -Os -march=i686 -ffreestanding -Wall -Werror reboot.c -o reboot.o
    i386-elf-gcc -c -g -Os -march=i686 -ffreestanding -Wall -Werror sleep.c -o sleep.o

    ld -static -Tlink.ld -nostdlib --nmagic -o boot.elf boot.o init.o print.o reboot.o sleep.o
    objcopy -O binary boot.elf boot.bin
