#include <stdio.h>

#define MAX_LINE    4096
#define MAX_WORD    256
#define MAX_WIDTH   64
#define NL          '\n'

int line_indexer(char str[], int start, int len);

int main(void)
{
    int c;
    char line[MAX_LINE];
    int i = 0;

    while ((c = getchar()) != EOF)
    {
        if (i + 1 >= (MAX_LINE - 1))
        {
            /* prematurely call line folder here if buff
             * getting filled while line not depleted
             */
            continue;
        }

        line[i++] = c;
        if (c == NL)
        {
            
            line[i] = '\0';
            int start = 0;
            int stop = 0;
            int linelen = 0;
            int wordlen;

            int j;
            while (stop < i)
            {
                stop = line_indexer(line, start, i);
                wordlen = stop - start;

                if ((linelen + wordlen) > MAX_WIDTH+1)
                {
                    putchar(NL);
                    linelen = wordlen;
                }
                else
                    linelen += wordlen;

                for (j = start; j < stop; ++j)
                    putchar(line[j]);
                start = stop;
            }

            memset(line, 0, MAX_LINE);
            i = 0;
        }
    }

    return 0;

}

int line_indexer(char str[], int start, int len)
{
    int nb = 0; /* 1 if we see a non-blank char*/
    int bc = 0; /* 1 if we see a blank char*/
    int bca = 0;
    int nba = 0;    /* 1 if we see another non-blank char*/
    int c;  /* keep track of curr char*/

    int i;
    for (i = start; i < len; ++i)
    {
        c = str[i];
        if (c != '\t' && c != ' ' && c != '\n')
        {
            // c is nb
            // check if c is nb
            if (nb == 0 && bc == 1 && bca == 1)
            {
                break;
            }
            if (nb == 1 && bc == 1)
            {
                // seeing new word now
                break;
            }
            else
                if (nb == 0) nb = 1;
        }
        else if (c == '\t' || c == '\n' || c == ' ')
        {
            // c is bc
            if (bc == 0) bc = 1;
            if (bca == 0) bca = 1;
        }
    }
    return i;
}
