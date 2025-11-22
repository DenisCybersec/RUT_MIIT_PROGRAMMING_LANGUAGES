#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/**
 * @brief - Computes the result based on given formula.
 * @param input - parameter for calculation.
 * @param scale - additional coefficient for formula.
 * @return - computed value according to specification.
 */
double computeResult(const double input, const double scale);

/**
 * @brief - Application entry point.
 * @return - returns 0 if execution succeeds.
 */
int main()
{
    double input = 0;
    double scale = 1.1;
    printf("Enter x value: ");
    scanf("%lf", &input);
    printf("Result is %.2lf", computeResult(input, scale));
    return 0;
}

double computeResult(const double input, const double scale)
{
    if (input > 1.2)
    {
        return log(input)*M_PI;
    }
    else if (input < 1.2)
    {
        return (cos(pow(input, 2)) / sin(pow(input, 2))) + (scale * pow(input, 2)) / 2;
    }
    else
    {
        return 3;
    }
}
