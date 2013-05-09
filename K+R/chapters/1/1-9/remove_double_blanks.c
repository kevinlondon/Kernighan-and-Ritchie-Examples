#include <stdio.h>

/* Exercise 1-8
   Copy input to output, replacing each string of one or more blanks
   with a single blank. */

main()
{
    int c, lastchar;

    lastchar = 0;
    c = 0;
    while ((c = getchar()) != EOF){
        if (c == ' ' && lastchar == ' ')
            ;
        else
            putchar(c);

        lastchar = c;
    }
}