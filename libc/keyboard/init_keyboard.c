#include <keyboard.h>
#include <kernel/isr.h>
#include <sys/handler.h>
#include <stdio.h>

void init_keyboard() {
  register_interrupt_handler(IRQ1, &cli_keyboard_handler);
}
