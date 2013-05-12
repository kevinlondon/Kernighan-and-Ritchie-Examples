#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

/* Ex 1-19: Write a function that reverses the character string s.
            Use it to write a program that reverse input a line
            at a time. */

void reverse(char line[], int strlength);
int getlength(char line[], int limit);

main()
{
    int len;

    char line[MAXLINE];
    char rev_line[MAXLINE];

    while ((len = getlength(line, MAXLINE)) > 0){
        printf("Original: %s\n", line);
        reverse(line, len);
    }
}

/* reverse: Print a string in reverse */
void reverse(char s[], int strlen)
{
    int i;

    printf("Reversed: ");
    for (i=strlen; i >= 0; --i)
        putchar(s[i]);

    printf("\n");
}

/* getlength: find length of string, excluding newline at the end. */
int getlength(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i){
        s[i] = c;
    }
    s[i] = '\0';        /* the last character we hit will be a \n. Overwrite. */

    return i;
}

