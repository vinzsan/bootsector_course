__asm__(".code16gcc\n");

__attribute__((section(".rodata"))) char *str = "Memuat bootsector...\n\r";
__attribute__((section(".rodata"))) char *str1 = "Memuat Sistem Operasi...\n\r";
__attribute__((section(".rodata"))) char *str2 = "Error Sistem tidak di temukan...\n\r";

extern void print(char *str);
extern void reboot();
extern void sleep(unsigned short timeshort, unsigned char timeval);
extern void shutdown();
extern void printf(char *str, char color);
void main()
{
    __asm__ __volatile__(
        "mov $0x0003,%%ax\n\t"
        "int $0x10"
        :::
    );
    //print(str);
    print("Memuat bootsector\n\r");
    // printf(str1, 0x04);
    sleep(0x0000, 0x0020);
    print(str1);
    sleep(0x0000, 0x0050);
    print(str2);
    sleep(0x0000, 0x0010);
    shutdown();
    while (1)
    {
        __asm__ __volatile__("hlt");
    }
}
