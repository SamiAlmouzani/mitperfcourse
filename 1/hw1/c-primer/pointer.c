// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {  // What is the type of argv? char **
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172";
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print? 6

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid? because argv is a char**

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c;  // What is the type of pcc2? a const pointer to char

  // For each of the following, why is the assignment:
  //*pcc = '7';  // invalid? cannot change character inside the pointer
  pcc = *pcp;  // valid? yes, you can change the single const pointer to point in another memory address in memmory
  pcc = argv[0];  // valid? yes it is for same reason

  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
  //cp = *pcp;  // invalid? no because you its a 'const pointer' and that means it can't point to anywhere else in memory.
  //cp = *argv;  // invalid? no because you are trying to update cp to point into another place in memory 
  //                         when its a const pointer.
  *cp = '!';  // valid? yes because you are dereferencing and just changing the value at where the const pointer is pointing
  //                    to without having to change the location to where the const pointer is pointint to in memory.

  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  //cpc = *pcp;  // invalid? no because you can't change memory address to where its pointing to because it is a const pointer
  //cpc = argv[0];  // invalid? no because argv[0] is the memory address and you cannot set it to cpc because its a
  //                          const pointer and cannot change.
  //*cpc = '@';  // invalid? no because its a const char
  printf("argv[0] = %c\n", *argv[0]);
  printf("program finished executing.");

  return 0;
}
