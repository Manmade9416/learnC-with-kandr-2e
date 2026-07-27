/* This program prints a conversion table of Fahrenheit
 * temperatures to their Celsius equivalent using the formula:
 * Celsius = (5/9)*(Fahrenheit - 32). It teaches the basic 
 * syntax of arithmetics and how variables work in C. I have
 * added a little complication by writing a separate function
 * that just does the conversion instead of doing it all in
 * main, I don't think either is better than the other.*/

#include <stdio.h> // input output header from stdlib

#define LOWER 0    // Symbolic constants, useful to make
#define UPPER 300  // Characters that are significant to
#define STEP 20    // to the program more visible ??

float fah_cel_converter(float fahr) { 
    // takes a float arg and returns a float.
    // Converts fahrenheit temperature to a celsius temperature
    float celsius = (5.0 / 9.0) * (fahr - 32.0);
    return celsius;
}

int main(void) {
    // returns an integer as a success code &
    // prints the fahrenheit to celsius conversion table
    // using fah_cel_converter to do the conversion math.

    // Print fancy heading for the table
    printf("FAHRENHEIT TO CELSIUS\n");
    printf("**********************\n");
    printf("----------------------\n");

    // for loop variant of the temp converter is much less
    // verbose and doesn't require that I name a bunch of variables
    // but maybe at the cost readability idk.
    for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("| %d\t   | %.2f\n", fahr, fah_cel_converter(fahr));
    }
    printf("----------------------\n");

    return 0;

}

