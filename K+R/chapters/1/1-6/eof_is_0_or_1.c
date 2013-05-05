/* Verify that the expression getchar() != EOF is 0 or 1 */

#include <stdio.h>

main()
{
    int c;

    while (getchar() != EOF)
        printf("getchar != EOF\n");

    printf("Getchar now equals EOF (this may never be called).");
}