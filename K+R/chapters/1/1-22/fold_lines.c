/* Exercise 1-22. 
Write a program to ``fold'' long input lines into two or more shorter 
lines after the last non-blank character that occurs before the n-th 
column of input. Make sure your program does something intelligent with 
very long lines, and if there are no blanks or tabs before the 
specified column. */

#include <stdio.h>

#define MAXLINE     1000        /* maximum input line size */
#define LINELIM   80          /* Once it reaches this point, wrap it. */

int max;                    /* maximum length seen so far */

int splitline(int space);
int copy(int split);

/*
after the last non-blank character
before nth column of input

So track an index of the last blank or tab character.

"very long lines" - if buffer fills up, try to split it and process what exists
"if no blanks or tabs" - try to go up to to 20% more above the length of the line. 
if nothing exists, copy as is up to the length of the line. */

main()
{
    int len;                /* current line length */
    int c, i;                  
    int space;              /* last seen space index */
    char line[MAXLINE];       /* current input line */
    char shortline[MAXLINE];  /* split line saved here */

    i = 0;

    while ((c == getchar()) != EOF) {
        if (i => LINELIM)
            i = splitline();

        if (c == ' ' || c == '\t')
            space = i;
        line[i] = c;
    return 0;
}

/* splitline: split the line at the most convenient place, return new start index */
int splitline(int space)
{



}

/* copy: copy the pieces of the split line */
int copy(int split)
{
    ;
}

