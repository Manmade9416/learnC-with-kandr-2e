/* Print out copy of input in reverse
 */

#include <stdio.h>

#define MAXLEN 100000

void reverser(char ori[],size_t len) {

    for (size_t i = len; i > 0; --i) {
        putchar(ori[i]);
    }
    putchar(ori[0]);
}

int main() {

    int cha;
    size_t len = 0;
    char original[MAXLEN];
    memset(original, 0, MAXLEN);

    while ((cha = getchar()) != EOF) {
        original[len] = cha;
        ++len;
    }

    reverser(original, len);
    return 0;
}
