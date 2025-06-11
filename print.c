__asm__(".code16gcc\n");

void print(char *str){
    while(*str){
        __asm__ __volatile(
            "mov %0,%%al\n\t"
            "mov $0x0E,%%ah\n\t"
            "int $0x10"
            ::"r"(*str)
            :"ah","al"
        );
        str++;
    }
}

void printf(char* text, char color)
{
    char* video_mem = (char*)0xB8000;

    for(int i = 0; text[i] != '\0'; ++i)
    {
        video_mem[i * 2] = text[i];
        video_mem[i * 2 + 1] = color;
    }
}
