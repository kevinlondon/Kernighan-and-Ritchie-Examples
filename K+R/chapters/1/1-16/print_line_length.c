#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

/* Exercise 1-16
   Modify the main method of the example to print the length
   of arbitrarily long input lines and as much as possible
   of the text. */

/* print the longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    int index;              /* iterator index */

    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        printf("Len: %d. Line: ", len);
        for (index=0; index<len; ++index)
            putchar(line[index]);

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)    /* there was a line */
        printf("%s", longest);

    /* Exit and return successful */
    return 0;
}

/* my_getline:   read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy:   copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
