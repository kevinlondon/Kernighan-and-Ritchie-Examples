/* Exercise 1-22.
Write a program to ``fold'' long input lines into two or more shorter
lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with
very long lines, and if there are no blanks or tabs before the
specified column. */

#include <stdio.h>
#include <ctype.h>              /* for determining if something is char */

#define MAXLINE     1000        /* maximum input line size */
#define LINELIM   79          /* Once it reaches this point, wrap it. */

int my_getline(char s[]);

/*
after the last non-blank character
before nth column of input

So track an index of the last blank or tab character.

"very long lines" - if buffer fills up, try to split it and process what exists
"if no blanks or tabs" - try to go up to to 50% more above the length of the line.
if nothing exists, copy as is up to the length of the line. */

main()
{
    int len;                /* current line length */
    int space;              /* last seen space index */
    int nonchar;            /* last seen non-character index */
    char line[MAXLINE];       /* current input line */
    int i, count;
    int newbreak;             /* new linebreak index */

    space = 0;
    nonchar = 0;
    newbreak = 0;

    while ((len = my_getline(line)) > 0){
        if (len > LINELIM) {
            i = 0;
            count = 0;
            while (i < len){
                if (line[i] == ' ' || line[i] == '\t')
                    space = i;
                else if (!isalpha(line[i]))
                    nonchar = i;

                if (count >= LINELIM){
                    if (space > 0)
                        newbreak = space;
                    else if (count > (LINELIM * 1.5))
                        newbreak = nonchar;

                    if (newbreak > 0){
                        line[newbreak] = '\n';
                        count = 0;
                        space = 0;
                        nonchar = 0;
                        newbreak = 0;
                    }
                }
                ++count;
                ++i;
            }
        }
        printf(line);
    }

    return 0;
}

/* my_getline:   read a line into s, return length */
int my_getline(char s[])
{
    int c, i;

    for (i=0; i < MAXLINE-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}