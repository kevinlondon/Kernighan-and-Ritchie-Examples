/* Ex 1-20: Detab 
   Replaces tabs in input with proper number of blanks to space to the
   next tab stop. Assume a fixed set of tab stops, say every n coluns.
   Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define MAXLENGTH   1000    /* maximum expected line length */

int detab(char line[], int ncolumns, int maxlen);

main()
{
    int len;
    char line[MAXLENGTH];
    int ncolumns;


    ncolumns = 8;
    while ((len = detab(line, ncolumns, MAXLENGTH)) > 0)
        ;
}

int detab(char line[], int ncolumns, int maxlen)
{
    int i, c;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (c != '\t')
            putchar(c);
        else {
            /* Add one as it is a zero based index */
            while (((i+1) % ncolumns) > 0) {
                putchar(' ');
                ++i;
            }
            putchar(' ');
        }
        ++i;
    }

    if (c == '\n'){
        putchar('\n');
        ++i;
    }

    return i;
}