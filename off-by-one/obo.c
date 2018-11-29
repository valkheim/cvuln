/* Simple off-by-one overflow example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
foo(char *input)
{
  char buf[1024];

  strncpy(buf, input, sizeof (buf));

  buf[sizeof (buf)] = '\0';
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
