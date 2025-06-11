__asm__(".code16gcc\n");

void sleep(unsigned short timeshort,unsigned char timeval){
    __asm__ __volatile__(
        "mov $0x86,%%ah\n\t"
        "mov $0x0050,%%cx\n\t"
        "mov $0x0000,%%dx\n\t"
        "int $0x15"
        ::"r"(timeval),"r"(timeshort):"ah","cx","dx"
    );
}
