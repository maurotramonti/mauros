#include <shell.h>
#include <sys/opcode.h>
#include <kernel/tty.h>
#include <string.h>
#include <stdio.h>

const char* version_string = "OS Info: MaurOS alpha, build 03.01.2021";
const char* help_string = "\nCLEAR:        PULISCE LA CONSOLE\n"
                          "GUI:          AVVIA L\'INTERFACCIA GRAFICA (ESC PER USCIRE)\n"
                          "HELP:         MOSTRA QUESTO AIUTO\n"
                          "VER:          FORNISCE INFORMAZIONI SUL SISTEMA\n";

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
    case OP_CODE_GUI:
      printf("GUI isn't implemented yet.\n");
      break;
    default:
      printf("OS Error: undefined opcode ");
      printf(itoa(opcode));
      putchar('\n');
      break;
  }
}
