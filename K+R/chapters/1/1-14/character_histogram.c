#include <stdio.h>

/* 1-14: Count all characters and print frequency. */

# define NUMCHARS 128 
# define FIRSTCHAR 32

main()
{
    int c, x, chars[NUMCHARS];

    for (c = FIRSTCHAR; c < NUMCHARS; ++c)
        chars[c] = 0;

    while ((c = getchar()) != EOF){
        if (c >= FIRSTCHAR && c <= NUMCHARS)
            chars[c] += 1;
    }

    printf("characters\n");
    for (c = FIRSTCHAR; c < NUMCHARS; ++c){
        printf("  %c: ", c);
        for (x = 0; x < chars[c]; ++x)
            printf("x");

        printf("\n");
    }
}