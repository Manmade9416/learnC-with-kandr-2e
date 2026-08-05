/* Copy input to output in reverse
 */

#include <stdio.h>

#define MAXLEN 1024 // Max line length/size

int getline2(char buff[]) {

    int cha;
    int count = 0;

    while ((cha = getchar()) != EOF && count < (MAXLEN - 1)) {

        if (cha == '\n') {
            buff[count] = cha;
            ++count;
            break;
        }

        buff[count] = cha;
        ++count;
    }

    buff[count] = '\0';
    return count;
}


void reverser(char ori[],size_t len) {
    /* Print's input string back to output in reverse
     * 1 char at a time starting from the last char
     * to the first in the string/char array
     */

    for (size_t i = len - 1; i > 0; --i) {
        if (ori[i] == '\n')
            continue;
        putchar(ori[i]);
    }
    putchar(ori[0]);
    putchar('\n');  // Advance to new line for readability
}

int main() {

    int cha;
    size_t len = 0;
    char original[MAXLEN];
    memset(original, 0, MAXLEN);

    while ((len = getline2(original)) > 0) {
        reverser(original, len);
    }

    return 0;
}
