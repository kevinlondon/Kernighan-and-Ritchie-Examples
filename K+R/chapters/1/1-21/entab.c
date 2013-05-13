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
    int first_space, last_space, gap, to_tab;

    i = 0;
    first_space = 0;
    last_space = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (c != ' '){
            while (first_space < last_space){
                gap = last_space - first_space;
                to_tab = (first_space+1) % ncolumns;
                if (to_tab > gap){
                    putchar(' ');
                    ++first_space;
                }
                else {
                    putchar('\t');
                    first_space += to_tab;
                }
                putchar(' ');
                ++first_space;
            }
            if (last_space > 0){
                i = last_space;
                first_space = 0;
                last_space = 0;
            }
            putchar(c);
        }
        else if (first_space == 0){
            first_space = i;
            last_space = i;
        }
        else {
            last_space = i;
        }
        ++i;
    }

    if (c == '\n'){
        putchar('\n');
        ++i;
    }

    return i;
}