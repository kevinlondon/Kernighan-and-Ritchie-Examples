#include <stdio.h>

/* count lines in input */
main()
{
    int c, nl, blanks, tabs;

    nl = 0;
    blanks = 0;
    tabs = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;

        if (c == ' ')
            ++blanks;
        
        if (c == '\t')
            ++tabs;

    printf("Newlines: %d\n", nl);
    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
}