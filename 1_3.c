#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculates the secondary current value
 * @param totalCurrent total current in the circuit
 * @param lampCurrent current through the first lamp
 * @return computed current for the second lamp
 */
double computeSecondaryCurrent(const double totalCurrent, const double lampCurrent);

/**
 * @brief Determines the resistance value
 * @param voltage applied voltage
 * @param current circuit current
 * @return calculated resistance
 */
double computeResistance(const double voltage, const double current);

/**
 * @brief Reads a numeric value from user input with validation
 * @return entered numeric value
 */
double readInput();

/**
 * @brief Ensures the provided value is positive
 * @param number value to be validated
 */
void validatePositive(const double number);

/**
 * @brief Entry point of the program
 * @return returns 0 if execution completed successfully
 */
int main(void)
{
    const double voltage = 220.0;
    printf("Enter total current: ");
    double totalCurrent = readInput();
    validatePositive(totalCurrent);
    
    printf("Enter first lamp current: ");
    double lampCurrent = readInput();
    validatePositive(lampCurrent);
    
    printf("Second lamp current = %.2lf\n", computeSecondaryCurrent(totalCurrent, lampCurrent));
    printf("Resistance = %.2lf", computeResistance(voltage, computeSecondaryCurrent(totalCurrent, lampCurrent)));

    return 0;
}

double computeSecondaryCurrent(const double totalCurrent, const double lampCurrent)
{
    return totalCurrent - lampCurrent;
}

double computeResistance(const double voltage, const double current)
{
    return voltage / current;
}

double readInput()
{
    double number = 0;
    if (!scanf("%lf", &number))
    {
        printf("Input error\n");
        abort();
    }
    return number;
}

void validatePositive(const double number)
{
    if (number <= 0)
    {
        printf("The value must be greater than zero\n");
        abort();
    }
}
