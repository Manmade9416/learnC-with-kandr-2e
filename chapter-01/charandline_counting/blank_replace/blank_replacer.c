#include <stdio.h>
#include <stdbool.h>

int main(void) {
    /* Copy input to output but replaces any string
     * of blanks with 1 blank.
     * so if line has a sequence of 10 blanks the ouput
     * is the same but with the 10 blanks squashed into just
     * one blank */

    int cha;
    bool seen_blank = false; // if blank already seen it's true

    while ((cha = getchar()) != EOF) {

        if (cha == '\t' || cha == ' ') {
            if (seen_blank) {
                continue;
            } else {
                putchar(cha);
                seen_blank = true;
            }
        } else {
            putchar(cha);
            if (seen_blank) { seen_blank = false; }
        }
    }

    return 0;
}

/* Maybe would be better if TABs were replaced by tabs instead
 * of just spaces and spaces only replaced by spaces?. */
