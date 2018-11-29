void bar(void)
{
  puts("I'm in bar");
}

void foo(void)
{
  int d;
  int *p;
  p = &d;
  *(p+2) = bar;
}

int main()
{
  printf("main %p\n", main);
  printf("foo  %p\n", foo);
  printf("bar  %p\n", bar);
  foo();
}
