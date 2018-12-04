#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char *hidden = "Congratulations! This is the hidden string!";

static int euid;

int
main(int argc, char *argv[])
{
  int age;
  int *age_ptr = &age;
  char name[32];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s name age\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  euid = geteuid();

  strcpy(name, argv[1]);

  *age_ptr = atoi(argv[2]);

  printf("%s is %d years old\n", name, age);

  if (euid != 0) {
    printf("Sorry %s, access to the hidden string is denied\n", argv[1]);
  } else {
    printf("%s\n", hidden);
  }

  return (0);
}
