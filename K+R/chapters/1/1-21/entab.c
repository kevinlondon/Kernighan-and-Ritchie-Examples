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
    head = 0;
    tail = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (c != ' '){
            while (head <= tail && head > 0){
                gap = (tail - head) + 1;
                to_tab = ncolumns - ((head) % ncolumns);
                //printf("Head: %d, Tail: %d, Index: %d, Gap: %d, To_Tab: %d\n", head, tail, i, gap, to_tab);
                if (to_tab > 0 && gap >= to_tab) {
                    putchar('\t');
                    head += to_tab;
                }
                else {
                    putchar(' ');
                    ++head;
                }
            }
            head = 0;
            tail = 0;
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