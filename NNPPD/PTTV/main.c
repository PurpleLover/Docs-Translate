#include "grammar.c"

int main(int argc, char *argv[]) {
  if (argc > 1) {
    f = fopen(argv[1], "rt");
  } else {
    f = fopen("Test.pl0", "rt");
  }
  Ch = ' ';
  do {
    Token = getToken();
    program();
  } while (Token != NONE);
  fclose(f);
}