#include <stdio.h>

/* count digits, white space, others */
main()
{
    int c, i, x, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits\n");
    for (i = 0; i < 10; ++i)
    {
        printf("  %d: ", i);
        for (x = 0; x < ndigit[i]; ++x)
            printf("x");
        
        printf("\n");
    }
    printf("white space = %d, other = %d\n",
        nwhite, nother);
}