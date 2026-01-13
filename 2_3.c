#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Converts angle measurement from radians to degrees
 * @param Input parameters from keyboard
 * @return Converted angle value in degrees
 */
double convertFromRadians();

/**
 * @brief Converts angle measurement from degrees to radians
 * @param Input parameters from keyboard
 * @return Converted angle value in radians
 */
double convertFromDegrees();

/**
 * @brief Reads a numeric value from keyboard input with validation
 * @return The read numeric value
 */
double readInputValue();

/**
 * @brief Validates that the input value is strictly positive
 * @param inputValue The value to be validated
 */
void validatePositiveValue(const double inputValue);

/**
 * @brief RADIANS_MODE - converts angle from radians to degrees
 * @brief DEGREES_MODE - converts angle from degrees to radians
 */
enum { RADIANS_MODE = 1, DEGREES_MODE = 2 };

/**
 * @brief Program entry point
 * @return Returns 0 if execution completed successfully
 */
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Select %d to convert radians to degrees or %d to convert degrees to radians: ", RADIANS_MODE, DEGREES_MODE);
    int selection = (int)readInputValue();
    switch (selection)
    {
    case(RADIANS_MODE):
        printf("Result in degrees: %lf", convertFromRadians());
        break;
    case(DEGREES_MODE):
        printf("Result in radians: %lf", convertFromDegrees());
        break;
    default:
        printf("Invalid selection");
        return 1;
    }
    return 0;
}

double convertFromRadians() {
    printf("Enter angle in radians: ");
    double radiansValue = readInputValue();
    validatePositiveValue(radiansValue);
    return radiansValue * 180 / (M_PI);
}

double convertFromDegrees() {
    printf("Enter angle in degrees: ");
    double degreesValue = readInputValue();
    validatePositiveValue(degreesValue);
    return degreesValue * (M_PI) / 180;
}

double readInputValue()
{
    double result = 0;
    if (!scanf("%lf", &result))
    {
        printf("Input error\n");
        abort();
    }
    return result;
}

void validatePositiveValue(const double inputValue)
{
    if (inputValue <= 0)
    {
        printf("Input must be positive\n");
        abort();
    }
}
