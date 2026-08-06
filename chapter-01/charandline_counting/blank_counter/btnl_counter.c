/* Blanks, Tabs and Newline Counter:
 * From C reference: Only Space and Tabs are classified as
 * Blanks. So we really counting Space, Tabs and Newlines
 */

#include <stdio.h>

int main(void) {
    size_t count = 0;
    int cha;

    while ((cha = getchar()) != EOF) {

        // Use '||' logical OR operator
        if (cha == ' ' || cha == '\t' || cha == '\n') {
            ++count;
        }
    }

    printf("%zu\n", count);
    return 0;
}
