/*
 * Outputs the input one word per line.
 * so `hello world how are you?` becomes:
 * hello
 * world
 * how
 * ...
 */

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int cha;
    bool seen_word = false;

    while ((cha = getchar()) != EOF) {

        if (cha == ' ' || cha == '\n' || cha == '\t') {
            if (seen_word) {
                putchar('\n');
                seen_word = false;
            }
        } else {
            putchar(cha);
            if (!seen_word) {
                seen_word = true;
            }
        }

    }
    return 0;
}
