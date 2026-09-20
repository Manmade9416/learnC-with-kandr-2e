#include <stdio.h>
#include <stdlib.h>

/* This is a test comment it should be removed
 * when running this program on itself
 */

// This is a test comment too

int main(int argc, char *argv[])
{
    if (argc != 2)
    {   // Tell user how to use program
        fprintf(stderr, "Usage: <%s> <cfile.c>\n", argv[0]);
        return 1;
    }

    FILE *STREAM = fopen(argv[1], "r");
    
    if (STREAM == NULL)
    {   // If file opening failed
        fprintf(stderr, "Failed to open %s", argv[1]);
        return 1;
    }

    char *buf = NULL;
    size_t size = 0;
    int mlcom = 0;  // for comments like /* */

    while (getline(&buf, &size, STREAM) != -1)
    {
        // Remove comments from line
        for (int i = 0; i <= size; ++i)
        {
            if (buf[i] == '/')
            {
                if (buf[i+1] == '/')
                {
                    buf[i] = '\n';
                    buf[i+1] = '\0';
                }
                else if (buf[i+1] == '*')
                {
                    if (mlcom == 0)
                        mlcom = 1;
                    buf[i] = '\n';
                    buf[i+1] = '\0';
                }
            }
            else if (buf[i] == '\'' || buf[i] == '"')
            {
                break;
            }
            else if (buf[i] == '*' && mlcom == 1)
            {
                if (buf[i+1] == '/')
                    mlcom = 0;
                buf[i] = '\n';
                buf[i] = '\0';
            }
        }

        // Print cleaned up line
        printf("%s", buf);

        // Reset buf and size to read again
        char *buf = NULL;
        size = 0;
    }

    free(buf);

    return 0;
}
