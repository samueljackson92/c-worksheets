#include <stdio.h>

#include "main.h"

int main ()
{
    int feet = 0;
    int inches = 0;
    char convert_more = 'n';
    double metres = 0;

    do
    {

        printf("Enter your height in feet\n");
        scanf("%d", &feet);

        printf("Enter your height in inches\n");
        scanf("%d", &inches);

        metres = convert_to_metric(feet, inches);

        printf("Your height in metres is: %.2f\n", metres);

        printf("Do you wish to convert more?\n");
        scanf(" %c", &convert_more); // space to consume the whitespace

    } while(convert_more == 'y');

    printf("Have a nice day. :)\n");
}

double convert_to_metric(const int feet, const int inches)
{
    const float INCH_TO_CENT_RATIO = 2.54;
    const int INCHES_IN_FOOT = 12;
    const int CENT_IN_METRE = 100;
    double centimetres = 0;

    centimetres = inches * INCH_TO_CENT_RATIO;
    centimetres += (feet * INCHES_IN_FOOT) * INCH_TO_CENT_RATIO;

    return centimetres / CENT_IN_METRE;
}
