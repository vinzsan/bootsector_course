#OUTPUT_FORMAT("binary")
ENTRY(_start)

SECTIONS
{
  . = 0x7C00;
  .text : AT(0x7C00)
  {
    *(.text)
    *(.data)
  }
  .sig : AT(0x7DFE)
  {
    SHORT(0xAA55)
  }
}
