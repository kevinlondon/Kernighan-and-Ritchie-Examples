#include <stdio.h>

/* print Celsius to Fahreheit table
   for celsius = 0, 20, ..., 300;
   Uses floating point conversion for accuracy. */
main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;              /* increments for degrees */

    celsius = lower;

    printf("Celsius to Fahrenheit Conversion\n");

    while (celsius <= upper) {
        fahr = ((9.0/5.0) * celsius) + 32;
        printf("%3.0f \t %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}