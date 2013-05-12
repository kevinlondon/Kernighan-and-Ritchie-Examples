#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

/* Ex 1-18: Write a program to remove trailing blanks and tabs from 
            each line of input. Delete blank lines. */

int trimline(char line[], int limit);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = trimline(line, MAXLINE)) > 0)
        if (len > 0)        /* \n lines will have a length of 1 */
            printf("Trimmed: %s\n", line);
}

/* trimline:  Remove trailing blanks and whitespaces. Delete empty lines. 
              Return length of line after trim. */
int trimline(char s[], int lim)
{
    int c, i, last_char;

    last_char = 0;      /* tracks last non-blank or tab character index */
    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){
        s[i] = c;
        if (c != '\t' && c != ' '){
            last_char = i;
        }
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[last_char+1] = '\0';
    return last_char;
}
