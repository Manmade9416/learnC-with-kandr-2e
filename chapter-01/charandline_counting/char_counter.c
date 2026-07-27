/* keep reading char from stdin if it's not a EOF:
 *  ignore count if the char is a new line
 *  if not increment our count by 1
 *
 * when it eventually runs into EOF char:
 * print whatever count it has.*/

#include <stdio.h>

int main(void) {
    double count = 0.0;
    int ch;
    
    while ((ch = getchar()) != EOF) {
        
        // could remove if block if want to count \n char
        if (ch == '\n') {
            continue;
        }
        ++count;
    }
    
    printf("Final Count = %.0f\n", count);

    return 0;
}
    
