#include <shell.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static size_t pass = 0;
static char n_str[30];
static char minuendo[10];
static char subtracting[10];
static char sign = ' ';

void sub() {
  if (pass == 0) {
    pass = 1;
    readline("Minuendo: ", n_str, true, sub);

  }
  else if (pass == 1) {
    pass = 2;
    strcpy(minuendo, n_str);
    readline("Subtracting: ", n_str, true, sub);



    }

  else if (pass == 2) {
    strcpy(subtracting, n_str);
    printf("\n");
    if (atoi (minuendo) == 0xBAD || atoi (subtracting) == 0xBAD) {
      printf(" You should enter only numbers! Exit.\n MaurOS > ");
      strempty(n_str);
      strempty(minuendo);
      strempty(subtracting);
      sign = ' ';
      pass = 0;
      return;
    }
    int result = atoi(minuendo) - atoi(subtracting);
    put_dbg(itoa(result));
    if (result < 0) sign = '-';
    printf("\n Result: %c %s\n MaurOS > ", sign, itoa(result));
    strempty(minuendo);
    strempty(subtracting);
    strempty(n_str);
    sign = ' ';
    pass = 0;
  }

}
