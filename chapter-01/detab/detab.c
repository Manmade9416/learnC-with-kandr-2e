/* k&r excercise 1-20
 * detab program
 */
#include <stdio.h>

#define TAB_STOP    8  /* Tab stop ever 8 columns */
#define TAB         '\t'  /* Char we're looking for*/
#define SPACE       ' ' /* char to replace tabs by*/
#define NEW_LINE    '\n'

int main()
{
    int c;
    size_t w = 0;      /* width/column num */
    size_t nsp = 0;     /* number of spaces to insert*/

    while ((c = getchar()) != EOF)
    {
        if (c == TAB)
        {
            /* will always result in a result > 0*/
            nsp = TAB_STOP - (w % TAB_STOP);
            
            /* increment w by n spaces, we'll be adding*/
            w += nsp;  

            while (nsp > 0)
            {
                putchar(SPACE);
                --nsp;
            }

        }
        else
        {
            putchar(c);

            /* if at newline then must reset w to 0*/
            (c == NEW_LINE) ? w = 0 : ++w;
        }
    }
    return 0;
}
