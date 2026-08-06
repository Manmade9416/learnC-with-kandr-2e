/* Line counter. Since lines are separated by \n
 * counting lines is like counting new lines */

#include <stdio.h>

int main(void) {
    size_t count = 0;
    int cha;

    while ((cha = getchar()) != EOF) {
        if (cha == '\n') {
            ++count;
        }
    }

    printf("%zu", count);
    return 0;
}
