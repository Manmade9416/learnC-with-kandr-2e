/* Replaces any series of blanks in the input with the min
 * amount of spaces and tabs needed to achieve the same
 * spacing as the input
 */

#include <stdio.h>

#define TABSTOP 8

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
            
            if ((row_len + blank_len) % TABSTOP == 0) {
                row_len += blank_len;
                blank_len = 0;
                putchar('\t');
            }

            else {
                while ((cha = getchar()) == ' ') {
                    ++blank_len;
                }

                /* Put back none space char to be handled by outer loop*/
                ungetc(cha, stdin);
                
                if ((row_len + blank_len) % TABSTOP == 0) {

                    int i;
                    for (i = blank_len; i > 0; i -= TABSTOP) {
                        putchar('\t');
                    }
                    row_len += blank_len;
                    blank_len = 0;
                }
                else if ((row_len + blank_len) % TABSTOP != 0) {

                    if (((row_len + blank_len) % TABSTOP) == 0) 
                    {
                    }
                }
            }
        }
    }

    return 0;
}
