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
    char *word = malloc(100*sizeof(char)); // Hold word
    memset(word, 0, 100);   // Wipe the entire array?
    bool in_word = false;   // In word or not
    bool first = false;     // Track first word for title

    while ((cha = getchar()) != EOF && l < 100*sizeof(char)) {

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
                first = true;
            }

            for (int i = 0; i <= l; ++i) 
                printf(GREEN"█"RESET);
            printf("\n");

            l = 0;  // Reset word len
            char *temp = malloc(100*sizeof(char));
            memset(temp, 0, 100);
            word = temp;    // Reset word to empty array?
            in_word = false;

            free(temp);
        }
    }

    free(word);
    return 0;
}




