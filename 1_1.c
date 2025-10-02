#include <math.h>
#include <stdio.h>

/* @brief Calculate A based on formula
 * @input x - value of x variable
 * @input y - value of y variable
 * @input z - value of z variable
 * @return value, calculated based on formula
 * */
const double calcA(const double x, const double y, const double z);

/* @brief Calculate B based on formula
 * @input x - value of x variable
 * @input y - value of y variable
 * @input z - value of z variable
 * @return value, calculated based on formula
 * */
const double calcB(const double x, const double y, const double z);

int main(void) {
  const double x = 1.7;
  const double y = 1.08;
  const double z = 0.5;
  printf("%.6lf\n", calcA(x, y, z));
  printf("%.6lf\n", calcB(x, y, z));
  return 0;
}

const double calcA(const double x, const double y, const double z) {
  return 3 * pow(x, y) * log(y) + exp(z * x);
}

const double calcB(const double x, const double y, const double z) {
  return exp(-z * x) * sqrt(x + 1) + exp(-y * x);
}
