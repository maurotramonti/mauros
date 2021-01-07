#include <shell.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static size_t pass = 0;
static char addend_str[30];
static char first_addend[10];
static char second_addend[10];

void add() {
  if (pass == 0) {
    pass = 1;
    readline("Addend: ", addend_str, true, add);

  }
  else if (pass == 1) {
    pass = 2;
    strcpy(first_addend, addend_str);
    readline("Addend: ", addend_str, true, add);



    }

  else if (pass == 2) {
    strcpy(second_addend, addend_str);
    printf("\n");
    if (atoi (first_addend) == 0xBAD || atoi (second_addend) == 0xBAD) {
      printf(" You should enter only numbers! Exit.\n MaurOS > ");
      strempty(addend_str);
      strempty(first_addend);
      strempty(second_addend);
      pass = 0;
      return;
    }
    int result = atoi(first_addend) + atoi(second_addend);
    printf("\n Result: %s\n MaurOS > ", itoa(result));
    strempty(addend_str);
    strempty(first_addend);
    strempty(second_addend);
    pass = 0;
  }

}
