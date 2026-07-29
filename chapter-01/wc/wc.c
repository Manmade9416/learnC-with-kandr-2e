/*
 * Count Characters, Words and Lines from input
 * This is a rough implementation that seems to work
 * but is not identical to the one in the books.
 */

#include <stdio.h>
#include <stdbool.h>

// ANSI escape codes to show color
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

int main(void) {
    int cha;
    size_t line_count = 0;
    size_t char_count = 0;
    size_t word_count = 0;
    bool seen_word = false;

    while ((cha = getchar()) != EOF) {
        ++char_count;

        if (cha == ' ' || cha == '\t') {

            if (seen_word) { 
                ++word_count;
                seen_word = false;
            }

        } else if (cha == '\n') {

            if (seen_word) {
                ++word_count;
                ++line_count;
                seen_word = false;
            } else {
                ++line_count;
            }

        } else if (cha) {

            if (seen_word != true) {
                seen_word = true;
            }
        }
    }
    
    printf("\nCharacters = "GREEN"%zu\n"RESET, char_count);
    printf("Words = "GREEN"%zu\n"RESET, word_count);
    printf("Lines = "GREEN"%zu\n"RESET, line_count);
    return 0;
}
