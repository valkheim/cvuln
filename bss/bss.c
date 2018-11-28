/* Simple BSS-based overflow example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int
check(char *secret, char *name)
{
  /* Only display the secret to the root user */
  if (geteuid() != 0) {
    printf("Sorry %s, access to the secret is denied\n", name);
  } else {
    printf("%s", secret);
  }

  return (0);
}

int
main(int argc, char *argv[])
{
  static char *secret = "This is the secret string\n";
  static char name[16];
  static int (*funcptr)(char *, char *);

  /* Check usage */
  if (argc != 2) {
    printf("Usage: %s username\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  /* Initialise function pointer */
  funcptr = check;

  /* Copy in the name */
  strcpy(name, argv[1]);

  /* Call the function */
  (*funcptr)(secret, name);

  return (0);
}
