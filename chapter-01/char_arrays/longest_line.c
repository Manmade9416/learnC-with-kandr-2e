#include <stdio.h>

#define MAXLINE 1000    // Max len of any line we can accept

// Green color to highlight longest line in output
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

int gtline(char line[],int max) {

    int c, i;

    for (i = 0; i < max && ((c = getchar()) != EOF && c != '\n'); ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';
    return i;
}

void cpy(char from[], char to[]) {
    
    int i = 0;
    char curr;

    while ((curr = from[i]) != '\0') {
        to[i] = curr;
        ++i;
    }

    if (curr == '\0') {
        to[i] = curr;
    }
}

int main() {
    int curr_len = 0;   // len of line curr being read
    int curr_max = 0;   // len of longest line seen so far
    char curr_line[MAXLINE];    // temp storage of curr line
    memset(curr_line, 0, MAXLINE);
    char longest[MAXLINE];      // store longest line seen so far
    memset(longest, 0, MAXLINE);

    while ((curr_len = gtline(curr_line, MAXLINE)) > 0) {

        if (curr_len > curr_max) {
            /* if curr line being read is bigger than
             * biggest one we have so far.*/
            curr_max = curr_len;
            cpy(curr_line, longest);
        }
    }

    printf(GREEN"\n\'%s\'"RESET, longest);
    return 0;

}
