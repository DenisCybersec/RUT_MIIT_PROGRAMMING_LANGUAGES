#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

/**
 * @brief Calculates the angle value in degrees.
 * @param radians Angle value in radians.
 * @return The calculated value in degrees.
 */
double radians_to_degrees(const double radians);

/**
 * @brief Calculates the angle value in minutes (arcminutes).
 * @param radians Angle value in radians.
 * @return The calculated value in arcminutes.
 */
double radians_to_minutes(const double radians);

/**
 * @brief Calculates the angle value in seconds (arcseconds).
 * @param radians Angle value in radians.
 * @return The calculated value in arcseconds.
 */
double radians_to_seconds(const double radians);

/**
 * @brief Program entry point.
 * @return Returns 0 on successful execution.
 */
int main(void) {
  double radians = 0;
  printf("Enter your angle (radians): ");
  scanf("%lf", &radians);
  printf("Angle in degrees: %.2lf\n", radians_to_degrees(radians));
  printf("Angle in minutes: %.2lf\n", radians_to_minutes(radians));
  printf("Angle in seconds: %.2lf\n", radians_to_seconds(radians));
  return 0;
}

double radians_to_degrees(const double radians) {
  return radians * (180.0 / M_PI);
}
double radians_to_minutes(const double radians) {
  return (radians * (180.0 / M_PI)) * 60;
}
double radians_to_seconds(const double radians) {
  return (radians * (180.0 / M_PI)) * 60 * 60;
}

