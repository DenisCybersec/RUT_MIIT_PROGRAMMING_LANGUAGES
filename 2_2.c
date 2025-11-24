#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

/**
 * @brief - Computes the result based on given formula.
 * @param x - variable for calculation.
 * @param a - additional coefficient for formula.
 * @return - computed value according to specification.
 */
double computeResult(const double x, const double a);

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

double computeResult(const double x, const double a)
{
    if (x > 1.2)
    {
        return log(x)*M_PI;
    }
    else if (x < 1.2)
    {
        return (cos(pow(x, 2))/ sin(pow(x, 2))) + (a*pow(x, 2)) / 2;
    }
    else
    {
        return 3;
    }
}
