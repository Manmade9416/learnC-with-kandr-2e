/* Everyone starts with a hello world as their introduction
 * to any language. this one shows the basic structure of a
 * C program and introduces a few C features that are important
 * to the language like #include to tell the compiler what to
 * include in our program, and main(), every C program must have
 * it as it is a special function name in C */

#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");

    return 0;
}

/* basic description of the program is as follows:
 * line 8: Tells the compiler to include the input output header
 * file from the standard library.
 * line 9: Empty so it is ignored
 * line 10: Defines a function that takes no arguments ((void)) and
 * returns a value of type integer (int) and also the curly braces
 * to open a block where the code of our function will live ({)
 * line 11: uses a function from the stdlib we included to print the
 * text "Hello, World!\n" to the console, the ';' terminates our statement.
 * line 12: Empty
 * line 13: we return the integer 0, anything calline this function would
 * get 0 in return.
 * line 14: closing curly braces to indicate the end of our function's code. */
