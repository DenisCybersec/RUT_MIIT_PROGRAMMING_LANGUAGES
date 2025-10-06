#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.1415
#endif

/**
 * @brief Read angle from standard input
 * @return Value from standard input
 */
double readValue();

/**
 * @brief Turn radian angle into degrees
 * @param[in] radian - angle in radians
 * @return Angle in degrees
 * */
double radianToDegree(double radian);

/**
 * @brief Turn radian angle into minutes
 * @param[in] radian - angle in radians
 * @return Angle in minutes
 */
double radianToMinutes(double radian);

/**
 * @brief Turn radian angle into seconds
 * @param[in] radian - angle in radians
 * @return Angle in seconds
 */
double radianToSeconds(double radian);

/**
 * @brief Turn radian angle into degrees, minutes and seconds and print pretty
 * prettyOutput
 * @param[in] radian - angle in radians
 * @return void
 */
void prettyOutput(double radian);

/**
 * @brief Read value using readValue function, print it. Turn it into degrees,
 * minutes and seconds and display it
 * @param void - no args should be passed
 */
int main() {
  const double radianAngle = readValue();
  printf("%.6f", radianAngle);
  prettyOutput(radianAngle);
  return 0;
}

double radianToDegree(double radian) { return radian * 180 / M_PI; }

double radianToMinutes(double radian) { return radianToDegree(radian) * 60; }

double radianToSeconds(double radian) { return radianToDegree(radian) * 3600; }

double readValue() {
  double inputVal = 0;
  printf("Enter angle in radians: ");
  scanf("%lf", &inputVal);
  printf("\n");
  return inputVal;
}

void prettyOutput(double radian) {
  printf("Angle in degrees %.6f\n", radianToDegree(radian));
  printf("Angle in minutes %.6f\n", radianToMinutes(radian));
  printf("Angle in seconds %.6f\n", radianToSeconds(radian));
}
