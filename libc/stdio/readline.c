#include <stdio.h>
#include <kernel/isr.h>
#include <string.h>
#include <stdbool.h>
#include <sys/handler.h>

static char buffer[256];
static size_t index = 0;

static char *variabile;
static isr_t callback;

static bool has_to_callback;

static void enter() {
  strempty(variabile);
  strncpy(variabile, buffer,  index - 1);
  index = 0;
  register_interrupt_handler(IRQ1, cli_keyboard_handler);
  if (has_to_callback) callback(0);
  else printf("\n MaurOS > ");

}

static void readline_handler() {
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
      buffer[index] = '1';
      index++;
      break;
    case 0x3:
      printf("2");
      buffer[index] = '2';
      index++;
      break;
    case 0x4:
      printf("3");
      buffer[index] = '3';
      index++;
      break;
    case 0x5:
      printf("4");
      buffer[index] = '4';
      index++;
      break;
    case 0x6:
      printf("5");
      buffer[index] = '5';
      index++;
      break;
    case 0x7:
      printf("6");
      buffer[index] = '6';
      index++;
      break;
    case 0x8:
      printf("7");
      buffer[index] = '7';
      index++;
      break;
    case 0x9:
      printf("8");
      buffer[index] = '8';
      index++;
      break;
    case 0xA:
      printf("9");
      buffer[index] = '9';
      index++;
      break;
    case 0xB:
      printf("0");
      buffer[index] = '0';
      index++;
      break;
    case 0x10:
      printf("Q");
      buffer[index] = 'Q';
      index++;
      break;
    case 0x11:
      printf("W");
      buffer[index] = 'W';
      index++;
      break;
    case 0x12:
      printf("E");
      buffer[index] = 'E';
      index++;
      break;
    case 0x13:
      printf("R");
      buffer[index] = 'R';
      index++;
      break;
    case 0x14:
      printf("T");
      buffer[index] = 'T';
      index++;
      break;
    case 0x15:
      printf("Y");
      buffer[index] = 'Y';
      index++;
      break;
    case 0x16:
      printf("U");
      buffer[index] = 'U';
      index++;
      break;
    case 0x17:
      printf("I");
      buffer[index] = 'I';
      index++;
      break;
    case 0x18:
      printf("O");
      buffer[index] = 'O';
      index++;
      break;
    case 0x19:
      printf("P");
      buffer[index] = 'P';
      index++;
      break;
    case 0x1E:
      printf("A");
      buffer[index] = 'A';
      index++;
      break;
    case 0x1F:
      printf("S");
      buffer[index] = 'S';
      index++;
      break;
    case 0x20:
      printf("D");
      buffer[index] = 'D';
      index++;
      break;
    case 0x21:
      printf("F");
      buffer[index] = 'F';
      index++;
      break;
    case 0x22:
      printf("G");
      buffer[index] = 'G';
      index++;
      break;
    case 0x23:
      printf("H");
      buffer[index] = 'H';
      index++;
      break;
    case 0x24:
      printf("J");
      buffer[index] = 'J';
      index++;
      break;
    case 0x25:
      printf("K");
      buffer[index] = 'K';
      index++;
      break;
    case 0x26:
      printf("L");
      buffer[index] = 'L';
      index++;
      break;
    case 0x2C:
      printf("Z");
      buffer[index] = 'Z';
      index++;
      break;
    case 0x2D:
      printf("X");
      buffer[index] = 'X';
      index++;
      break;
    case 0x2E:
      printf("C");
      buffer[index] = 'C';
      index++;
      break;
    case 0x2F:
      printf("V");
      buffer[index] = 'V';
      index++;
      break;
    case 0x30:
      printf("B");
      buffer[index] = 'B';
      index++;
      break;
    case 0x31:
      printf("N");
      buffer[index] = 'N';
      index++;
      break;
    case 0x32:
      printf("M");
      buffer[index] = 'M';
      index++;
      break;
    case 0x39:
      printf(" ");
      buffer[index] = '\0';
      index++;
      break;
    case 0x0E:
      if (index > 0) {
        putchar('\b');
        index--;
        buffer[index] = '\0';
      }
      break;
    case 0x2B:
      printf("\\");
      buffer[index] = '\\';
      index++;
      break;
    case 0x34:
      printf(".");
      buffer[index] = '.';
      index++;
      break;
    case 0x28:
      printf("\'");
      buffer[index] = '\'';
      index++;
      break;
    case 0x0C:
      printf("-");
      buffer[index] = '-';
      index++;
      break;
    case 0x33:
      printf(",");
      buffer[index] = ',';
      index++;
      break;
    case 0x1A:
      printf("[");
      buffer[index] = '[';
      index++;
      break;
    case 0x1B:
      printf("]");
      buffer[index] = ']';
      index++;
      break;
    case 0x0D:
      printf("=");
      buffer[index] = '=';
      index++;
      break;
    case 0x27:
      printf(";");
      buffer[index] = ';';
      index++;
      break;
    default:
      break;
  }
}


void readline(const char* msg, char* var, bool has_callback, isr_t back_function) {
  index = 0;
  register_interrupt_handler(IRQ1, readline_handler);
  printf("\n %s ", msg);
  variabile = var;
  callback = back_function;
  has_to_callback = has_callback;
}
