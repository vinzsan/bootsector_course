__asm__(".code16gcc\n");

void reboot() {
    __asm__ __volatile__ (
        "cli\n\t"               
        "mov $0xFE,%%al\n\t"
        "out %%al,$0x64\n\t"
        "hlt\n\t"           
        :::"al"
    );
}

void shutdown() {
    __asm__ __volatile__ (
        "cli\n\t"                    
        "movw $0x2000, %%ax\n\t"     
        "movw $0x604, %%dx\n\t"      
        "out %%ax, %%dx\n\t"         
        "hlt\n\t"                    
        :
        :
        : "ax", "dx"
    );
}
