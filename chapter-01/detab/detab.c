/* Replaces TABS with 4 spaces
 */

#include <stdio.h>

#define DETAB   4

int main() {

    int cha;

    while ((cha = getchar()) != EOF) {

        if (cha == '\t') {
            for (int i = 0; i <= DETAB; ++i)
                putchar(' ');
        }
        else if (cha != '\t')
            putchar(cha);
    }

    return 0;
}
