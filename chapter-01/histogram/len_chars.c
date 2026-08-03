/* Count Number of appearances of every char in input.
 * Use count to draw histogram. */

#include <stdio.h>
#include <stdlib.h>

// ANSI escape codes to show color
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

int main(void) {
    int cha;
    int n = 0;
    int *characters = malloc(150000*sizeof(int));
    memset(characters, 0, 150000);

    while ((cha = getchar()) != EOF) {
        characters[n] = cha;
        ++n;
    }


    int *seen = malloc(75000*sizeof(int));
    memset(seen, 0, 75000);
    int skip = 0;
    size_t count = 0; 

    // Heading and start of graph
    printf("\nChar Appearance Histogram\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("\n%4sX\n", "");

    for (int i = 0; i <= n; ++i) {

        for (int l = 0; l <= n; ++l) {
            if (characters[i] == seen[l]) {
                skip = 1;
            }
        }

        if (skip == 1) { 
            skip = 0;
            count = 0;
            continue;

        }

        for (int j = i+1; j <= n; ++j ) {
            if (characters[i] == characters[j]) 
                ++count;
        }

        if (characters[i] == '\n' || characters[i] == '\t' || characters[i] == ' ') 
            printf(" %3s┃", "");
        else
            printf("%c%3s┃", characters[i], "");

        if (count <= 50) {
            for (int k = 0; k <= count; ++k)
                printf(GREEN"█"RESET);
            printf("\n");
        }
        else {
            for (int k = 0; k <= 50; ++k)
                printf(GREEN"█"RESET);
            printf(">50\n");
        }

        seen[i] = characters[i];
        count = 0;
    }

    // Print out the bottom piece of the histogram
    printf("%4s╋", "");

    for (int i = 0; i < 53; ++i)
        printf("━");

    printf(" Y");
    printf("\n");
    printf("%4s0", "");

    for (int i = 10; i <= 55; i += 10)
        printf("%10d", i);

    
    free(characters);
    free(seen);
    return 0;
}




