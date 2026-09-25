/*k&r excercise 1-21 entab program*/
#include <stdio.h>

#define TAB_STOP    8 /* width of tab*/
#define SPACE       ' ' /* char we looking for*/
#define TAB         '\t' /* 1/2 char to replace by */
#define NEW_LINE    '\n'

int main()
{
    int c;
    size_t w = 0;   /* width/len of line*/
    size_t nsp = 0; /* n of sequential spaces seen*/

    while ((c = getchar()) != EOF)
    {
        if (c == SPACE)
        {
            // handle counting of spaces
            nsp = 1;
            while ((c = getchar()) == SPACE) ++nsp;

            if (nsp >= TAB_STOP)
            {
                // atleast 1 full tab needed
                while (nsp >= TAB_STOP)
                {
                    putchar(TAB);
                    nsp -= TAB_STOP;
                    /* advance to the next tabstop*/
                    w = (w / TAB_STOP + 1) * TAB_STOP;
                }
            }
            
            if (nsp > 0 && ((w + nsp) % TAB_STOP) == 0)
            {
                putchar(TAB);
                nsp = 0;
                ++w;
            }
            else
            {
                int i;
                for (i = 0; i < nsp; ++i) putchar(SPACE);
                w += nsp;
                nsp = 0;
            }

            // handle char that stopped while loop
            putchar(c);
            ++w;
        }
        else if (c == NEW_LINE)
        {
            // reset w to 0
            putchar(c);
            w = 0;
        }
        else
        {
            // increment w
            putchar(c);
            ++w;
        }
    }


}
