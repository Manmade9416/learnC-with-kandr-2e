/* Print lines that have 80 or more characters from input
*/

#include <stdio.h>

#define SHORTEST 80
#define LONGEST  10000
#define MAXLINES 100000

void cpy(char from[], char to[], size_t start, size_t stop) {
    /* Copy lines of 80 chars or more to the another
     * array */

    for (size_t i = start; i <= stop; ++i) {
        if (from[i])
            to[i] = from[i];
    }
}

int main() {

    int cha;
    char line[LONGEST];
    char long_lines[MAXLINES];

    memset(line, 0, LONGEST);
    memset(long_lines, 0, MAXLINES);

    size_t line_len = 0;
    size_t start = 0;

    while((cha = getchar()) != EOF) {
        if (line_len < (LONGEST - 1) && cha != '\n') {
            line[line_len] = cha;
            ++line_len;
        }
        else if (line_len > (LONGEST -1))
            continue;
        else if (cha == '\n' && line_len < SHORTEST)
            line_len = 0;

        if (cha == '\n' && line_len >= SHORTEST) {
            line[line_len] = cha;
            ++line_len;
            cpy(line, long_lines, start, line_len);
            start = line_len;
        }

        // memset(line, 0, LONGEST);
    }

    if (line_len)
        // printf("%s", long_lines);
        for (int i = 0; i <= line_len; ++i) {
            if (long_lines[i] == '\n') {
                putchar(long_lines[i]);
                putchar('\n');
            }
            else 
                putchar(long_lines[i]);
        }

    return 0;
}
