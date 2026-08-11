/* Replaces any series of blanks in the input with the min
 * amount of spaces and tabs needed to achieve the same
 * spacing as the input
 */

#include <stdio.h>

#define TABSTOP 4

int main(void) {

    int cha;
    int row_len = 0;
    int blank_len = 0;

    while ((cha = getchar()) != EOF) {

        if (cha == '\n') { 
            row_len = 0;
            putchar(cha);
        }

        if (cha != ' ' && cha != '\n' && cha != '\t') {   
            ++row_len;
            putchar(cha);
        }
        else if (cha == '\t') {
            ++row_len;
            putchar(cha);
        }
        else if (cha == ' ') {
            ++blank_len;
            
            if (row_len % TABSTOP == 0) {
                printf("%d", row_len);
                row_len += blank_len;
                blank_len = 0;
                putchar('\t');
            }

            else {
                while ((cha = getchar()) == ' ') {
                    ++blank_len;
                }
                if ((row_len + blank_len) % TABSTOP == 0) {

                    int i;
                    for (i = blank_len; i > 0; i -= TABSTOP) {
                        putchar('\t');
                    }
                    putchar(cha);
                    row_len += blank_len + 1;
                    blank_len = 0;
                }
                else if ((row_len + blank_len) % TABSTOP != 0) {

                    if ((row_len - 1) % TABSTOP == 0) {

                        int i;
                        for (i = blank_len - 1; i > 0; i -= TABSTOP) {
                            putchar('\t');
                        }
                        row_len += blank_len + 2;
                        putchar(' ');
                        putchar(cha);
                        blank_len = 0;
                    }
                    else {
                        printf("%d", blank_len);
                        int i;
                        for (i = blank_len; i > 0; --i) {
                            putchar(' ');
                        }
                        row_len += blank_len + 1;
                        putchar(cha);
                        blank_len = 0;
                    }
                }
            }
        }
    }

    return 0;
}

