__asm__(".code16gcc\n\tjmpl $0x0000,$_start\n");

__attribute__((section("._start"),used))
void _start(){
    __asm__ __volatile__("jmpl $0x000,$main\n");
    while(1)
        __asm__("nop");
}
