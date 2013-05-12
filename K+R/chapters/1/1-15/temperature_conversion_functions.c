#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

float convert_to_celsius(int fahr);
float convert_to_fahrenheit(int celsius);
int print_formatted(int old_temp, float new_temp);

/* test power function */
main()
{
    int fahr, celsius;

    printf("Fahrenheit to Celsius Readings\n");
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        print_formatted(fahr, convert_to_celsius(fahr));

    printf("\n");

    printf("Celsius to Fahrenheit Readings\n");
    for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
        print_formatted(celsius, convert_to_fahrenheit(celsius));

    return 0;
}

/* fahrenheit: convert from celsius temp to fahrenheit and return. */
float convert_to_fahrenheit(int celsius)
{
    return ((9.0/5.0) * celsius) + 32;
}

/* convert_to_celsius: take fahrenheit and return celsius reading. */
float convert_to_celsius(int fahr)
{
    return (5.0/9.0) * (fahr-32);
}

/* print_formatted: use a standardized print for both temp readings. */
int print_formatted(int old_temp, float new_temp)
{
    printf("%3d\t to\t %6.1f\n", old_temp, new_temp);
}