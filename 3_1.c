#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *  @brief reads a double value from stdin with input validation
 *  @return the read value
 *  */
double read_input_value();

/**
 * @brief verifies that the increment is positive
 * @param increment the value to check
 * */
void validate_increment(const double increment);

/**
 * @brief checks whether the function argument belongs to its domain
 * @param t - function argument
 * @return true if the argument is in the domain, otherwise false
 * */
bool is_in_domain(const double t);

/**
 * @brief computes function value y by the given formula
 * @param t argument value
 * @return computed y
 * */
double compute_y(const double t);

/**
 * @brief Program entry point
 * @return returns 0 on successful execution
 */
int main() {
  printf("Enter begin value: ");
  double left = read_input_value();
  printf("Enter end value: ");
  double right = read_input_value();
  printf("Enter step: ");
  double delta = read_input_value();
  validate_increment(delta);
  for (double t = left; t < right + DBL_EPSILON; t = t + delta) {
    if (is_in_domain(t)) {
      printf("x = %.2lf, y = %.4lf\n", t, compute_y(t));
    } else {
      printf("x = %.2lf, doesn't belong to DOF\n", t);
    }
  }
  return 0;
}

double read_input_value() {
  double v = 0;
  if (scanf("%lf", &v) != 1) {
    printf("Error\n");
    abort();
  }
  return v;
}

void validate_increment(const double increment) {
  if (increment <= DBL_EPSILON) {
    printf("Error, step should be possitive\n");
    abort();
  }
}

bool is_in_domain(const double t) { return (1 + 2 * t + pow(t, 2)) > 0; }

double compute_y(const double t) { return log(1 / (1 + 2 * t + pow(t, 2))); }
