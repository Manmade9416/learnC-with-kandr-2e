/* This program is to verify the difference in behaviour
 * between ((c = getchar()) != EOF) && (c = getchar() != EOF),
 * emphasizing the behaviour of operator precedence in C. */

#include <stdio.h>  // sym const EOF is defined in here.

int main(void) {
    int c;
    
    /* This will get a warning from the compiler,
     * wrap `c = getchar()` in () to get the character 
     * you enterd copied back to you.
     *
     * Also after consulting the AIs, this broken version
     * will not print anything, because 0 and 1 happen to be 
     * NUL and SOH respectively which are control codes and 
     * will not be visible to you.
     * to see the 0 and 1 you'd have to use 
     * printf("%d", c)instead but you will always get 1 in
     * my xp because you need EOF to get 0 which is Ctrl+D
     * I think so.*/

    while (c = getchar() != EOF) {
        putchar(c);
        // printf("%d\n", c);
    }

    // Correct version
    /* while ((c = getchar() != EOF)) {
        putchar(c);
    }*/


    return 0;
}

    
