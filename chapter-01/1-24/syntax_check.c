/* k&r excercise 1-24:
 *
 * Simple syntax error checker.
 *
 * it currently only checks for single and double quotes,
 * escapes and single line comments
 *
 * When it runs into what it thinks is a syntax error it simply
 * shouts "Missing x on line y" with x being the thing that's missing
 */

#include <stdio.h>

#define DOUBLE_Q      '"'
#define SINGLE_Q      '\''
#define B_SLASH     '\\'
#define NEWLINE      '\n'
#define SLASH     '/'

int main(void)
{
    int c;
    int incomment = 0;
    int instring = 0;
    int inliteral = 0;
    int linenumber = 1;
    
    while ((c = getchar()) != EOF)
    {
        if (c == SLASH)
        {
            if (instring == 0 && inliteral == 0)
            {
                if (!incomment) incomment = 1;
                else if (incomment == 1) incomment = 2;
            }

        }

        else if (c == DOUBLE_Q)
        {
            if (!incomment && !inliteral)
            {
                if (!instring) instring = 1;
                else if (instring == 1) instring = 2;
                else if (instring == 2) instring = 1;
            }
        }
        
        else if (c == SINGLE_Q)
        {
            if (!incomment && !instring)
            {
                if (!inliteral) inliteral = 1;
                else if (inliteral == 1) inliteral = 2;
                else if (inliteral == 2) inliteral = 1;
            }
        }

        else if (c == B_SLASH)
        {
            /* consume the next char*/
            int pac;
            if ((pac = getchar()) == NEWLINE) linenumber++;
        }

        else if (c == NEWLINE)
        {

            /* incorrect single line comment*/
            if (incomment == 2) incomment = 0;
            else if (incomment == 1)
            {
                {
                    printf("Missing '/' in line %d\n", linenumber);
                    return 0;
                }
            }

            /* unclosed char literal*/
            if (inliteral == 2) inliteral = 0;
            else if (inliteral == 1)
            {
                printf("Missing \' in line %d\n", linenumber);
                return 0;
            }

            /* unclosed string*/
            if (instring == 2) instring = 0;
            else if (instring == 1)
            {
                printf("Missing \" in line %d\n", linenumber);
                return 0;
            }
            linenumber++;
        }
    }
    char dummy[] = "Hello \
                    World!";
    return 0;
}
