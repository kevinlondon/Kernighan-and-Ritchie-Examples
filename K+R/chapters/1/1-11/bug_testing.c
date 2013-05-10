#include <stdio.h>

#define IN      1   /* inside a word */
#define OUT     0   /* outside a word */

/* count lines, words, and characters in input */
/* Test in a more robust manner by including additional control characters. */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t' || c == '\b' || c == '\\')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}