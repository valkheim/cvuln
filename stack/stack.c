/* Simple stack-based overflow example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
foo(char *input)
{
  char buf[16];

  strcpy(buf, input);
}

void
bar(void)
{
  printf("I've been hacked\n");
}

int
main(int argc, char **argv)
{
  if (argc != 2) {
    printf("Usage: %s input_string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  foo(argv[1]);

  return (0);
}
