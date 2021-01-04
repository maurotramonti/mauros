#include <shell.h>
#include <sys/opcode.h>
#include <kernel/tty.h>
#include <string.h>
#include <stdio.h>
#include <debug.h>
#include <stdint.h>
#include <sys/handler.h>

const char* version_string = "OS Info: MaurOS alpha, build 04.01.2021";
const char* help_string = "\nCLEAR:        CLEARS THE SCREEN\n"
                          "HELP:         SHOWS THIS HELP\n"
                          "UPTIME:       SHOWS SYSTEM UPTIME"
                          "VER:          SHOWS VERSION NUMBER AND DATE\n";

unsigned int ticks, seconds;

void sh_run(int opcode) {
  switch(opcode) {
    case OP_CODE_VER:
      printf("%s\n", version_string);
      break;
    case OP_CODE_CLS:
      terminal_initialize();
      break;
    case OP_CODE_HLP:
      printf("%s\n", help_string);
      break;
    case OP_CODE_UPT:
      ticks = timer_get_ticks();
      seconds = ticks / 50;
      printf("System uptime: %s\n", itoa(seconds));
      break;
    default:
      put_fail("OS Error: undefined opcode: ");
      printf("%s\n", itoa(opcode));
      break;
  }
}
