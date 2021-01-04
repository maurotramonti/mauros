#include <keyboard.h>
#include <kernel/isr.h>
#include <sys/handler.h>
#include <debug.h>


void init_keyboard() {
  register_interrupt_handler(IRQ1, cli_keyboard_handler);
  put_dbg("Connected IRQ1 to cli_keyboard_handler()");
}
