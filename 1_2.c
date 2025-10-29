#include <math.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
/**
 * @brief Read angle from standard input
 * @return Value from standard input
 */
double readValue();

/**
 * @brief Turn radian angle into degrees
 * @param[in] radian - angle in radians
 * @return Angle in degrees
 */
double radianToDegree(const double radian);

/**
 * @brief Turn radian angle into minutes
 * @param[in] radian - angle in radians
 * @return Angle in minutes
 */
double radianToMinutes(const double radian);

/**
 * @brief Turn radian angle into seconds
 * @param[in] radian - angle in radians
 * @return Angle in seconds
 */
double radianToSeconds(const double radian);

/**
 * @brief Turn radian angle into degrees, minutes and seconds and print pretty
 * prettyOutput
 * @param[in] radian - angle in radians
 * @return void
 */
void prettyOutput(const double radian);

/**
 * @brief Enter point of program
 * @return 0 on cucess
 */
int main() {
  const double radianAngle = readValue();
  printf("%.6f", radianAngle);
  prettyOutput(radianAngle);
  return 0;
}

double radianToDegree(const double radian) { return radian * 180 / M_PI; }

double radianToMinutes(const double radian) {
  return radianToDegree(radian) * 60;
}

double radianToSeconds(const double radian) {
  return radianToDegree(radian) * 3600;
}

double readValue() {
  double inputVal = 0;
  printf("Enter angle in radians: ");
  scanf("%lf", &inputVal);
  printf("\n");
  return inputVal;
}

void prettyOutput(const double radian) {
  printf("Angle in degrees %.6f\n", radianToDegree(radian));
  printf("Angle in minutes %.6f\n", radianToMinutes(radian));
  printf("Angle in seconds %.6f\n", radianToSeconds(radian));
}
