#include <shell.h>
#include <sys/opcode.h>
#include <kernel/tty.h>
#include <string.h>
#include <stdio.h>
#include <sys/handler.h>
#include <power.h>
#include <time.h>

const char* version_string = "OS Info: MaurOS v7.1.21-alpha";
const char* help_string = "\n ADD:          print the sum of two addends"
                          //"\n SUB:          print the difference between two numbers"
                          "\n CHLOG:        changes since last version"
                          "\n CLEAR:        clear the screen"
                          "\n HELP:         show this help"
                          "\n REBOOT:       reboot the system"
                          "\n SHUTDOWN:     shutdown the system (only QEMU)"
                          "\n UPTIME:       show system uptime (in seconds)"
                          "\n VER:          show version number\n";

const char* changes_string = "\n Changes since v7.1.21-alpha:\n"
                             "  \a Math commandd: ADD\n"
                             "  \a Math function: avrg()\n"
                             "  \a Shell bugfixes\n";



void sh_run(int opcode) {
  unsigned int ticks, seconds;
  switch(opcode) {
    case OP_CODE_VER:
      printf(" %s\n MaurOS > ", version_string);
      break;
    case OP_CODE_CLS:
      terminal_clear(6);
      printf(" MaurOS > ");
      break;
    case OP_CODE_HLP:
      printf(" %s\n MaurOS > ", help_string);
      break;
    case OP_CODE_UPT:
      ticks = timer_get_ticks();
      seconds = ticks / 50;
      printf(" System uptime: ");
      seconds_to_minutes(seconds);
      printf("\n MaurOS > ");
      break;
    case OP_CODE_CHL:
      printf(" %s\n MaurOS > ", changes_string);
      break;
    case OP_CODE_RBT:
      reboot();
      break;
    case OP_CODE_SHD:
      outw(0x604, 0x2000); /* NOTE: Only works in QEMU */
      break;
    case OP_CODE_ADD:
      add();
      break;
    case OP_CODE_SUB:
      //sub();
      break;
    default:
      put_fail(" OS Error: undefined opcode: ");
      printf(" %s\n MaurOS > ", itoa(opcode));
      break;
  }
}
