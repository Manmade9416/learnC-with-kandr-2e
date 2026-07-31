/* Prints a horizontal histogram using the length of each
 * word in the input as it's own bar
 *
 * Version 1 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ANSI escape codes to show color
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"



int main(void) {
    int cha;    // Hold individual chars
    int l = 0;  // how long the word is

    char *word = malloc(1000*sizeof(char)); // Hold word
    memset(word, 0, 1000);   // Wipe the entire array?

    bool in_word = false;   // In word or not
    bool first = false;     // Track first word for title

    while ((cha = getchar()) != EOF && l < 1000*sizeof(char)) {

        if (cha != ' ' && cha != '\n' && cha != '\t') {
            word[l] = (char)cha;
            ++l;
            if (!in_word) 
                in_word = true;
        } 
        else {
            // ############
            // ######
            // ################
            // ...

            if (!first) {
                printf("\nWord Length Histogram\n");
                printf("━━━━━━━━━━━━━━━━━━━━━\n");
                printf("\n%-6sX\n", "");
                first = true;
            }
            
            if (l > 6) {
                for (int i = 0; i < 3; ++i)
                    putchar(word[i]);
                printf("...┃");
            }
            else
                printf("%-6s┃", word);

            if (l > 50) {
                for (int i = 0; i < 50; ++i) {
                    printf(GREEN"█"RESET); 
                }
                printf(">50");
                printf("\n");
            }
            else {
                for (int i = 0; i < l; ++i) 
                    printf(GREEN"█"RESET);
                printf("\n");
            }

            l = 0;
            memset(word, 0, 1000);
            in_word = false; 

            if (cha == '\n')
                break;
        }
    }
    
    // Print out the bottom piece of the histogram
    printf("%-6s╋", "");

    for (int i = 0; i < 53; ++i)
        printf("━");

    printf(" Y");
    printf("\n");
    printf("%-6s0", "");

    for (int i = 10; i <= 49; i += 10)
        printf("          %d", i);

    free(word);
    return 0;
}




