/* Count Number of appearances of every char in input.
 * Use count to draw histogram. */

#include <stdio.h>
#include <stdlib.h>

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
                printf("█");
            printf("\n");
        }
        else {
            for (int k = 0; k <= 50; ++k)
                printf("█");
            printf(">50\n");
        }

        seen[i] = characters[i];
        count = 0;
    }
    
    free(characters);
    free(seen);
    return 0;
}




