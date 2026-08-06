/* 
 * Replaces TABS the appropriate n of spaces.
 * With n = 4, count every char and reset count to 0 when
 * count >= n. Then when the char == \t, just do n - count
 * to get the number of spaces to enter.
 * finally \n char resets the count because the previous
 * line's count is no longer needed 
 * */

#include <stdio.h>

#define TABSTOP   4     /* This is n*/

int main() {

    int cha;
    int col = 0;    /* This is count*/

    while ((cha = getchar()) != EOF) {

        if (cha == '\n') {  /* reset count on \n*/
            putchar(cha);
            col = 0;
            continue;
        }

        if (cha == '\t') {
            int i;
            if (col != TABSTOP) {
                for (i = 1; i <= (TABSTOP - col); ++i)
                    putchar(' ');
            }
            else
                for (i = 1; i <= TABSTOP; ++i)
                    putchar(' ');
            col = 0;
        }
        else if (cha != '\t') {
            putchar(cha);
            if (col >= TABSTOP)
                col = 0;
            ++col;
        }
    }

    return 0;
}
