#include <shell.h>
#include <sys/opcode.h>
#include <kernel/tty.h>
#include <string.h>
#include <stdio.h>
#include <debug.h>
#include <stdint.h>
#include <sys/handler.h>

const char* version_string = "OS Info: MaurOS  v5.1.21-alpha";
const char* help_string = "\nCHLOG:        CHANGES SINCE LAST VERSION"
                          "\nCLEAR:        CLEARS THE SCREEN"
                          "\nHELP:         SHOWS THIS HELP"
                          "\nUPTIME:       SHOWS SYSTEM UPTIME"
                          "\nVER:          SHOWS VERSION NUMBER AND DATE\n";

const char* changes_string = "Changes since v5.1.21-alpha:\n"
                             " \a Added support to command completion\n"
                             " \a Added support to shell history\n"
                             " \a Removed useless debug info\n"
                             " \a New functions: strncpy(), put_int(), terminal_writestring_color()\n";

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
    case OP_CODE_CHL:
      printf("%s\n", changes_string);
      break;
    default:
      put_fail("OS Error: undefined opcode: ");
      printf("%s\n", itoa(opcode));
      break;
  }
}
