#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*@brief Make pretty abort from programm
 * @param error_msg - message, that would be printed in stderr
 * */
void error(const char *error_msg);

/* @brief Read input from stdin and check, that it > 0
 * @return Value from stdin
 * */
double readInput();

/* @brief Compare 2 double and return 0 if they != and 1 if they are equal
 * @param fstDouble - first double to compare
 * @param sndDouble - second double to compare
 * @return 0 if they are not equal, 1 if they are equal
 * */
int compareDouble(double fstDouble, double sndDouble);

/* @brief Calculate amperage using formula Amp(snd_lamp) = Amp(circuit) -
 * Amp(fst_lamp)
 * @input circuitAmperage - amperage in circuit
 * @input firstLampAmperage - amperage in firstLamp
 * @return amperage in second lamp
 * */
double calculateAmperage(const double circuitAmperage,
                         const double firstLampAmperage);

/* @brief Calculate resistance using formula Resist = Voltage / amperage
 * @input voltage - voltage in lamp
 * @input amperage - amperage in lamp
 * @return resistance in lamp
 * */
double calculateResistanceInLamp(const double voltage, const double amperage);

int main(void) {
  const double voltageInCircuit = 220.0;
  double circuitAmperage = 0.0;
  double firstLampAmperage = 0.0;

  printf("Enter amperage in circuit: ");
  circuitAmperage = readInput();
  printf("\n");
  printf("Enter amperage in first lamp: ");
  firstLampAmperage = readInput();

  const double secondLampAmperage =
      calculateAmperage(circuitAmperage, firstLampAmperage);
  if (secondLampAmperage < 0) {
    error("Error, second lamp voltage is negative");
    return 1;
  }
  printf("Second lamp amperage = %.6lf\n", secondLampAmperage);
  printf("Second lamp resistance = %.6lf\n",
         calculateResistanceInLamp(voltageInCircuit, secondLampAmperage));
  return 0;
}

double readInput() {
  double inputValue = 0.0;
  scanf("%lf", &inputValue);
  if (inputValue > 0) {
    return inputValue;
  } else {
    error("Non-positive input error!");
    return -1.0;
  }
}

double calculateAmperage(const double circuitAmperage,
                         const double firstLampAmperage) {
  return circuitAmperage - firstLampAmperage;
}

double calculateResistanceInLamp(const double voltage, const double amperage) {
  if (compareDouble(voltage, 0.0)) {
    return voltage / amperage;
  } else {
    error("Div by zero error!");
    return -1.0;
  }
}

int compareDouble(double fstDouble, double sndDouble) {
  if (fabs(fstDouble - sndDouble) < 1e-6) {
    return 1;
  }
  return 0;
}

void error(const char *error_msg) {
  fprintf(stderr, "%s\n", error_msg);
  fflush(stderr);
  fflush(stdout);
  abort();
}
