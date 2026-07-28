/* Replace Backslashes, Backspaces with their Visible char,
 * And double prints all Backslashes.
 *       = \t
 * ^H = \b
 * \ = \\
 */

#include <stdio.h>

int main(void) {
    int cha;

    while ((cha = getchar()) != EOF) {
        if (cha == '\t') {
            printf("\\t");
        }
        else if (cha == '\b') {
            printf("\\b");
        }
        else if (cha == '\\') {
            printf("\\\\");
        }
        else {
            putchar(cha);
        }
    }

    return 0;
}
    

