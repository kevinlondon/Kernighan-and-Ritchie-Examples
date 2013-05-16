/* Ex 1-20: Detab 
   Replaces tabs in input with proper number of blanks to space to the
   next tab stop. Assume a fixed set of tab stops, say every n coluns.
   Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define MAXLENGTH   1000    /* maximum expected line length */

int entab(char line[], int ncolumns, int maxlen);

main()
{
    int len;
    char line[MAXLENGTH];
    int ncolumns;

    ncolumns = 8;
    while ((len = entab(line, ncolumns, MAXLENGTH)) > 0)
        ;
}

int entab(char line[], int ncolumns, int maxlen)
{
    int i, c;
    int head, tail, gap, to_tab;

    i = 0;
    head = 0;   /* first seen space in a sequence */
    tail = 0;   /* index for last seen space in a sequence */
    while ((c = getchar()) != EOF && c != '\n') {
        if (c != ' '){
            while (head <= tail && head > 0){
                // Distance between first space and last space
                gap = (tail - head) + 1;

                // Distance between the current head and the next tabstop
                to_tab = ncolumns - ((head) % ncolumns);
                if (to_tab > 0 && gap >= to_tab) {
                    putchar('\t');
                    head += to_tab;
                }
                else {
                    putchar(' ');
                    ++head;
                }
            }
            // Re-init the head/tail markers as they're for spaces.
            head = 0;
            tail = 0;

            // If it's a tab, adjust where we think we are in the line
            // by going to the next tab stop.
            if (c == '\t'){
                i += ncolumns - (i % ncolumns);
            }
            putchar(c);
        }
        else if (head == 0){
            head = i;
            tail = i;
        }
        else {
            tail = i;
        }
        ++i;
    }

    if (c == '\n'){
        putchar('\n');
        ++i;
    }

    return i;
}