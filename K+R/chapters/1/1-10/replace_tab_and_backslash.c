#include <stdio.h>

/* Copy input to output. 
   Replace tab with \t, backspace with \b, and backslash with \\. */

main()
{
    int c;


    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
}