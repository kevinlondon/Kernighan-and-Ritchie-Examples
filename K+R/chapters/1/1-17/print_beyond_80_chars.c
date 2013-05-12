#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */
#define MINLINE 80      /* minimum input line length */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
        if (len > MINLINE){
            printf("Length: %d, %s", len, line);
        }
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
