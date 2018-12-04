#include <stdio.h>
#include <limits.h>

unsigned int
foo(unsigned int a, unsigned int b)
{
  unsigned int c;

  /* Return rather than cause overflow to occur */
  if (UINT_MAX - a < b) {
    printf("Overflow would occur!\n");
    return (0);
  }

  /*
   * Having reached this point we know:
   *
   * UINT_MAX - a >= b
   *
   * We assert the above fact and the fact that overflow has occurred and
   * check the satisfiability of resulting system. If unsatisfiable then
   * we have proved overflow is impossible.
   */
  c = a + b;

  return (c);
}


int
main()
{
  return (0);
}
