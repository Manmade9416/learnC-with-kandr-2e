/* Copies input to output with trailing blanks, tabs and
 * empty lines removed
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 1024

int getline2(char buff[]) {
    
    int cha;
    int count = 0; 

    while ((cha = getchar()) != EOF) {
        
        if (cha == '\n') {
            buff[count] = cha;
            ++count;
            break;
        }
        else {
            buff[count] = cha;
            ++count;
        }
    }

    buff[count] = '\0';
    return count;
}


int stripper(char line[], int len) {
    int cha;
    bool nl = false;
    bool seenl = false;
    char l[MAX];
    memset(l, 0, MAX);

    if (len == 1)
        return 0;

    int i;
    for (i = len - 1; i >= 0; --i) {

        cha = line[i];

        if (cha == '\n') {
            l[i] = cha;
            if (nl == false)
                nl = true;
        }
        else if (cha == ' ' || cha == '\t') {
            if (nl == true)
                continue;
            else
                l[i] = cha;
        } 
        else {
            l[i] = cha;
            if (nl == true)
                nl = false;
            if (seenl == false)
                seenl = true;
        }
    }

    /* If we haven't seen anything but blanks and \n
     * treat as empty line
     */
    if (seenl == false)
        return 0;

    printf("%s", l);

    /* fix issue where null is there before \n
     * I don't understand why
     */
    if (l[len - 2] == '\0')
        printf("\n");

    return 0;
}

int main() {

    int count;
    char line[MAX];
    memset(line, 0, MAX);

    while ((count = getline2(line)) > 0) { 
        stripper(line, count);
        memset(line, 0, MAX);
    }

    return 0;
}

