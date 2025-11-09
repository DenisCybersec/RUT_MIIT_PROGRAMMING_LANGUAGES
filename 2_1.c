#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*@brief Make pretty exit from programm
 * @param error_msg - message, that would be printed in stderr
 * */
void error(const char *error_msg);

/*@brief Write message into stdout and read input from stdin
 * @param prompt - message to be printed in stdout
 * @return value from stdin*/
double promptDoubleInput(const char *prompt);

/*@brief Read double input from stdin and check, that it > 0
 * @return Value from stdin*/
double readDoubleInput();

/* @brief Read integer input from stdin and check, that it > 0
 * @return Value from stdin
 * */
int readIntegerInput();

/*@brief Read sides from stdin and calculate square of rectangle using a * b
 *formula
 *@return Square or rectangle*/
double calculateRectangle();

/*@brief Read sides from stdin and calculate square of triangle using Heron's
 *formula
 *@return Square or rectangle*/
double calculateTriangle();

/*@brief Reads user input to determine square user wants to calculate and
 * calculate its square*/
int main(void) {
  printf("Enter 1 to calculate square for rectangle\nEnter 2 to calculate "
         "square for triangle\nYour choice: ");
  int choice = readIntegerInput();
  double result = 0.0;
  switch (choice) {
  case 1:
    result = calculateRectangle();
    break;
  case 2:
    result = calculateTriangle();
    break;
  default:
    error("Wrong choice of calculation variant");
    return 1;
  }
  printf("Your square is %.6lf\n", result);
  return 0;
}

double calculateTriangle() {
  double a_side = promptDoubleInput("Enter a side: ");
  double b_side = promptDoubleInput("Enter b side: ");
  double c_side = promptDoubleInput("Enter c side: ");
  double half_perimeter = (a_side + b_side + c_side) / 2.0;
  return sqrt(half_perimeter * (half_perimeter - a_side) *
              (half_perimeter - b_side) * (half_perimeter - c_side));
}

double calculateRectangle() {
  double a_side = promptDoubleInput("Enter a side: ");
  double b_side = promptDoubleInput("Enter b side: ");
  return a_side * b_side;
}

double readDoubleInput() {
  double inputValue = 0.0;
  scanf("%lf", &inputValue);
  if (inputValue <= 0) {
    error("Non-positive input error!");
    abort();
  } 
  return inputValue;
}

int readIntegerInput() {
  int inputValue = 0.0;
  scanf("%d", &inputValue);
  if (inputValue <= 0) {
    error("Non-positive input error!");
    abort();
  } return inputValue;
}

void error(const char *error_msg) {
  fprintf(stderr, "%s\n", error_msg);
  fflush(stderr);
  fflush(stdout);
}

double promptDoubleInput(const char *prompt) {
  printf("%s", prompt);
  double result = readDoubleInput();
  return result;
}