/* Simple format string attack example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int y = 0;

int
main(int argc, char **argv)
{
  char buf[32];
  int x;

  if (argc != 2) {
    printf("Usage: %s input_string\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  x = 1;

  snprintf(buf, sizeof (buf), argv[1]);
  printf("buf: %s\n", buf);
  printf("len: %d\n", strlen(buf));
  printf("  x: %d\n", x);
  printf("  y: %d\n", y);

  return (0);
}
