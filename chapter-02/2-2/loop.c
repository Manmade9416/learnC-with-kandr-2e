#include <stdio.h>
/*
 * write a for loop equivalent to the one below
 * without the use of && and ||.
 * int i;
 * int c;
 * for (i = 0; i<lim-1 (c=getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c;
 */

int main(void)
{
    int lim = 1000;
    int i, c;
    char s[lim];

    for (i = 0; i<lim-1; ++i)
    {
        if ((c = getchar()) != '\n')
            if (c != EOF)
                s[i] = c;
            else
                break;
        else
            break;
    }

    s[i] = '\0';

    if (c == '\n')
        printf("%s\n", s);
    else
        printf("%s", s);

    return 0;
}

