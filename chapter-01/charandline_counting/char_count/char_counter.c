/* keep reading char from stdin if it's not a EOF:
 *  ignore count if the char is a new line
 *  if not increment our count by 1
 *
 * when it eventually runs into EOF char:
 * print whatever count it has.*/

#include <stdio.h>

int main(void) {
    size_t count = 0;
    int ch;
    
    while ((ch = getchar()) != EOF) {
        
        // uncomment to not count \n
        /*if (ch == '\n') {
            continue;
        }*/

        ++count;
    }
    
    printf("%zu\n", count);
    return 0;
}
    
