# apue page 41

1.how to include apue.h
-solution:
    gcc -I ../apue.3e/include
    or
    you copy apue.h to /usr/include

2._err_quit", referenced from:
      _main in ls-bf8e23.o
  "_err_sys", referenced from:
      _main in ls-bf8e23.o
    ld: symbol(s) not found for architecture x86_64
-solution:
    clang -c apue.3e/lib/error.c -I ../include
    clang -I ../apue.3e/include  ../apue.3e/lib/error.o  -g ls.c
