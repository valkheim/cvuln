#include <stdio.h>

enum {SIZE = 32};

void
foo(void)
{
  char buffer[SIZE];

  scanf("%s", buffer);
}

int
main(int argc, char *argv[])
{
  foo();

  return (0);
}
