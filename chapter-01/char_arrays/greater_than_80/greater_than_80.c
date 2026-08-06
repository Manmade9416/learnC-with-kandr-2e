/* Print lines that have 80 or more characters from input
*/

#include <stdio.h>

#define MINLEN  80
#define MAXLEN  1024

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

int main() {

    char line[MAXLEN];
    int len;
    memset(line, 0, MAXLEN);

    while ((len = getline2(line)) > 0) {
        
        if (len >= MINLEN) {
            printf("%s", line);
        }

        memset(line, 0, MAXLEN);
    }
    return 0;
}
