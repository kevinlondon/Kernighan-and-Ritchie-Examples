#include <stdio.h>

/* count characters in input; 2nd version */
main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        /* Body requires a statement. 
           In this case, we use a null statement to satisfy. */
        ;

    printf("%.0f\n", nc);
}