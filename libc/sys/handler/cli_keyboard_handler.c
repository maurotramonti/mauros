#include <sys/handler.h>
#include <stdio.h>
#include <kernel/tty.h>
#include <kernel/isr.h>
#include <stddef.h>
#include <sys/opcode.h>
#include <string.h>
#include <shell.h>

static char kbuffer[256];
static size_t index = 0;

static void enter() {
  putchar('\n');
  if (!strncmp(kbuffer, "VER", index)) sh_run(OP_CODE_VER);
  else if (!strncmp(kbuffer, "CLEAR", index)) sh_run(OP_CODE_CLS);
  else if (!strncmp(kbuffer, "HELP", index)) sh_run(OP_CODE_HLP);
  else if (!strncmp(kbuffer, "UPTIME", index)) sh_run(OP_CODE_UPT);

  else {
    printf("Unknown command: ");
    terminal_write(kbuffer, index);
    putchar('\n');
  }
  index = 0;
  printf("MaurOS > ");
}

void cli_keyboard_handler() {
  int scancode = inb(0x60);
  switch(scancode) {
        case 0x1C:
          enter();
          break;
        case 0x0:
          printf("ERROR");
          break;
        case 0x1:
          printf("ESC");
          break;
        case 0x2:
          printf("1");
          kbuffer[index] = '1';
          index++;
          break;
        case 0x3:
          printf("2");
          kbuffer[index] = '2';
          index++;
          break;
        case 0x4:
          printf("3");
          kbuffer[index] = '3';
          index++;
          break;
        case 0x5:
          printf("4");
          kbuffer[index] = '4';
          index++;
          break;
        case 0x6:
          printf("5");
          kbuffer[index] = '5';
          index++;
          break;
        case 0x7:
          printf("6");
          kbuffer[index] = '6';
          index++;
          break;
        case 0x8:
          printf("7");
          kbuffer[index] = '7';
          index++;
          break;
        case 0x9:
          printf("8");
          kbuffer[index] = '8';
          index++;
          break;
        case 0xA:
          printf("9");
          kbuffer[index] = '9';
          index++;
          break;
        case 0xB:
          printf("0");
          kbuffer[index] = '0';
          index++;
          break;
        case 0x10:
          printf("Q");
          kbuffer[index] = 'Q';
          index++;
          break;
        case 0x11:
          printf("W");
          kbuffer[index] = 'W';
          index++;
          break;
        case 0x12:
          printf("E");
          kbuffer[index] = 'E';
          index++;
          break;
        case 0x13:
          printf("R");
          kbuffer[index] = 'R';
          index++;
          break;
        case 0x14:
          printf("T");
          kbuffer[index] = 'T';
          index++;
          break;
        case 0x15:
          printf("Y");
          kbuffer[index] = 'Y';
          index++;
          break;
        case 0x16:
          printf("U");
          kbuffer[index] = 'U';
          index++;
          break;
        case 0x17:
          printf("I");
          kbuffer[index] = 'I';
          index++;
          break;
        case 0x18:
          printf("O");
          kbuffer[index] = 'O';
          index++;
          break;
        case 0x19:
          printf("P");
          kbuffer[index] = 'P';
          index++;
          break;
        case 0x1E:
          printf("A");
          kbuffer[index] = 'A';
          index++;
          break;
        case 0x1F:
          printf("S");
          kbuffer[index] = 'S';
          index++;
          break;
        case 0x20:
          printf("D");
          kbuffer[index] = 'D';
          index++;
          break;
        case 0x21:
          printf("F");
          kbuffer[index] = 'F';
          index++;
          break;
        case 0x22:
          printf("G");
          kbuffer[index] = 'G';
          index++;
          break;
        case 0x23:
          printf("H");
          kbuffer[index] = 'H';
          index++;
          break;
        case 0x24:
          printf("J");
          kbuffer[index] = 'J';
          index++;
          break;
        case 0x25:
          printf("K");
          kbuffer[index] = 'K';
          index++;
          break;
        case 0x26:
          printf("L");
          kbuffer[index] = 'L';
          index++;
          break;
        case 0x2C:
          printf("Z");
          kbuffer[index] = 'Z';
          index++;
          break;
        case 0x2D:
          printf("X");
          kbuffer[index] = 'X';
          index++;
          break;
        case 0x2E:
          printf("C");
          kbuffer[index] = 'C';
          index++;
          break;
        case 0x2F:
          printf("V");
          kbuffer[index] = 'V';
          index++;
          break;
        case 0x30:
          printf("B");
          kbuffer[index] = 'B';
          index++;
          break;
        case 0x31:
          printf("N");
          kbuffer[index] = 'N';
          index++;
          break;
        case 0x32:
          printf("M");
          kbuffer[index] = 'M';
          index++;
          break;
        case 0x39:
          printf(" ");
          kbuffer[index] = ' ';
          index++;
          break;
        case 0x0E:
          if (index > 0) {
            putchar('\b');
            index--;
            kbuffer[index] = ' ';
          }
          break;
        case 0x2B:
          printf("\\");
          kbuffer[index] = '\\';
          index++;
          break;
        case 0x34:
          printf(".");
          kbuffer[index] = '.';
          index++;
          break;
        case 0x28:
          printf("\'");
          kbuffer[index] = '\'';
          index++;
          break;
        case 0x0C:
          printf("-");
          kbuffer[index] = '-';
          index++;
          break;
        case 0x33:
          printf(",");
          kbuffer[index] = ',';
          index++;
          break;
        case 0x1A:
          printf("[");
          kbuffer[index] = '[';
          index++;
          break;
        case 0x1B:
          printf("]");
          kbuffer[index] = ']';
          index++;
          break;
        case 0x0D:
          printf("=");
          kbuffer[index] = '=';
          index++;
          break;
        case 0x27:
          printf(";");
          kbuffer[index] = ';';
          index++;
          break;
        default:
          break;
    }
}
