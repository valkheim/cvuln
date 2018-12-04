#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
foo(int (*funcptr)(const char *), char *name)
{
  char buffer[8];

  (*funcptr)("Your real name is...");
  strcpy(buffer, name);
  (*funcptr)(getenv("USER"));
}

int
main(int argc, char *argv[])
{
  int (*funcptr)(const char *);

  if (argc != 2) {
    fprintf(stderr, "Usage: %s yourname\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  funcptr = puts;

  foo(funcptr, argv[1]);

  return (0);
}
