#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * @brief Replace the second from end element of an array with a value.
 * @param arr Pointer to the integer array.
 * @param arr_size Number of elements in the array.
 * @param replaceValue Value to write into the second-from-end position.
 * @return void
 */
void replaceSecondFromEnd(int *arr, const size_t arr_size,
                          const int replaceValue);

/**
 * @brief Read and return array size from stdin.
 * @return The array size (must be > 0). Aborts on invalid input.
 */
size_t readArraySize();

/**
 * @brief Read a single integer from stdin.
 * @return The integer read. Aborts on invalid input.
 */
int readInteger();

/**
 * @brief Find the maximum absolute value in an array.
 * @param arr Pointer to the integer array.
 * @param arr_size Number of elements in the array (must be > 0).
 * @return Maximum absolute value among elements in the array.
 */
int findMaximumAbs(int *arr, const size_t arr_size);

/**
 * @brief Fill an array with random integers inside a user-provided interval.
 * @param arr Pointer to the integer array to fill.
 * @param arr_size Number of elements in the array.
 * @return void
 */
void feelRandomNumbers(int *arr, const size_t arr_size);

/**
 * @brief Read arr_size integers from stdin into arr.
 * @param arr Pointer to the integer array to fill.
 * @param arr_size Number of elements to read.
 * @return void
 */
void readNumbersFromStdin(int *arr, const size_t arr_size);

/**
 * @brief Print array elements separated by spaces.
 * @param arr Pointer to the integer array.
 * @param arr_size Number of elements to print.
 * @return void
 */
void printArray(int *arr, const size_t arr_size);

/**
 * @brief Count how many elements are divisible by n.
 * @param arr Pointer to the integer array.
 * @param arr_size Number of elements in the array.
 * @param n Divisor to test (if zero behavior: returns 0).
 * @return Count of elements divisible by n.
 */
size_t findAmountOfNDivs(int *arr, const size_t arr_size, const int n);

/**
 * @brief Find index of the first pair of adjacent elements with differing
 * signs.
 * @param arr Pointer to the integer array.
 * @param arr_size Number of elements in the array (must be > 1).
 * @return Index of the first element of the pair, or (size_t)-1 if none.
 */
size_t firstDiffSigns(int *arr, const size_t arr_size);

/**
 * @brief Read interval begin from stdin.
 * @return The interval begin value. Aborts on invalid input.
 */
int readIntervalBegin();

/**
 * @brief Read interval end from stdin.
 * @return The interval end value. Aborts on invalid input.
 */
int readIntervalEnd();

/**
 * @brief Validate that intervalBegin <= intervalEnd.
 * @param intervalBegin Interval start.
 * @param intervalEnd Interval end.
 * @return void (aborts on invalid interval).
 */
void checkInterval(const int intervalBegin, const int intervalEnd);

/**
 * @brief Fill array according to user choice (random or manual).
 * @param arr Pointer to the integer array to fill.
 * @param arr_size Number of elements to fill.
 * @return void
 */
void fillArray(int *arr, const size_t arr_size);

/**
 * @brief Check if an integer is negative.
 * @param n Integer to check.
 * @return true if n < 0, otherwise false.
 */
bool isNegative(const int n);

/**
 * @oaram randomFill - number used for choosing random filling
 * @oaram manualFIll - number used for choosing manual filling
 */
enum { randomFill = 1, manualFill = 2 };

/**
 * @brief Program entry point demonstrating array operations.
 * @return 0 on success; aborts on invalid inputs or allocation failure.
 */
int main(void) {
  const size_t n = readArraySize();
  int *arr = calloc(n, sizeof(int));
  if (!arr) {
    fprintf(stderr, "arr: Memory allocation failed: calloc returned NULL\n");
    abort();
  }
  fillArray(arr, n);
  printf("Your array is: ");
  printArray(arr, n);
  printf("\n");
  const int maximumAbs = findMaximumAbs(arr, n);
  int *arr_second = calloc(n, sizeof(int));
  if (!arr_second) {
    fprintf(stderr,
            "arr_second: Memory allocation failed: calloc returned NULL\n");
    abort();
  }
  memcpy(arr_second, arr, n * sizeof(int));
  replaceSecondFromEnd(arr_second, n, maximumAbs);
  printf("Replaced second from end element. New array is: ");
  printArray(arr_second, n);
  printf("\n");
  printf(
      "Enter number to check amount of numbers, that can be divided on it: ");
  const int x = readInteger();
  if (x == 0) {
    fprintf(stderr, "Division by zero in not defined");
    abort();
  } else {
    printf("Amount of numbers is: %zu", findAmountOfNDivs(arr, n, x));
    printf("\n");
  }
  const size_t fstElementNumberIs = firstDiffSigns(arr, n);
  if (fstElementNumberIs == (size_t)-1) {
    printf("No integers found with different signs\n");
  } else {
    printf("Number of first diff signs pair are %zu and %zu\n",
           fstElementNumberIs, fstElementNumberIs + 1);
  }
  free(arr);
  return 0;
}

size_t readArraySize() {
  size_t variable = 0;
  printf("Enter array size: ");
  if (scanf("%zu", &variable) != 1) {
    fprintf(stderr, "Failed to read array size from input\n");
    abort();
  }
  if (variable == 0) {
    fprintf(stderr, "Array size must be greater than 0\n");
    abort();
  }
  return variable;
}

int findMaximumAbs(int *arr, size_t arr_size) {
  if (arr_size == 0) {
    fprintf(stderr, "findMaximumAbs: arr_size must be > 0\n");
    abort();
  }
  int mx = arr[0];
  for (size_t i = 0; i < arr_size; i++) {
    if (abs(arr[i]) > abs(mx)) {
      mx = arr[i];
    }
  }
  return mx;
}

int readInteger() {
  int variable = 0;
  if (scanf("%d", &variable) != 1) {
    fprintf(stderr, "Failed to read integer from input\n");
    abort();
  }
  return variable;
}

void feelRandomNumbers(int *arr, size_t arr_size) {
  int beginInterval = readIntervalBegin();
  int endInterval = readIntervalEnd();
  checkInterval(beginInterval, endInterval);
  srand((unsigned)time(NULL));
  int range = endInterval - beginInterval + 1;
  for (size_t i = 0; i < arr_size; i++) {
    arr[i] = rand() % range + beginInterval;
  }
}

void readNumbersFromStdin(int *arr, size_t arr_size) {
  for (size_t i = 0; i < arr_size; i++) {
    arr[i] = readInteger();
  }
}

size_t findAmountOfNDivs(int *arr, size_t arr_size, int n) {
  if (n == 0) {
    return 0;
  }
  size_t counter = 0;
  for (size_t i = 0; i < arr_size; i++) {
    if (arr[i] % n == 0) {
      counter++;
    }
  }
  return counter;
}

bool isNegative(int n) { return n < 0; }

size_t firstDiffSigns(int *arr, size_t arr_size) {
  if (arr_size <= 1) {
    fprintf(stderr, "firstDiffSigns: arr_size must be > 1\n");
    abort();
  }
  for (size_t i = 1; i < arr_size; i++) {
    long prod = (long)arr[i] * (long)arr[i - 1];
    if (isNegative(prod)) {
      return i - 1;
    }
  }
  return (size_t)-1;
}

void replaceSecondFromEnd(int *arr, size_t arr_size, int replaceValue) {
  if (arr_size < 2) {
    fprintf(stderr, "replaceSecondFromEnd: arr_size must be >= 2\n");
    abort();
  }
  arr[arr_size - 2] = replaceValue;
}

void printArray(int *arr, size_t arr_size) {
  for (size_t i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
}

int readIntervalBegin() {
  int variable = 0;
  printf("Enter interval begin: ");
  if (scanf("%d", &variable) != 1) {
    fprintf(stderr, "Failed to read interval begin from input\n");
    abort();
  }
  return variable;
}

int readIntervalEnd() {
  int variable = 0;
  printf("Enter interval end: ");
  if (scanf("%d", &variable) != 1) {
    fprintf(stderr, "Failed to read interval end from input\n");
    abort();
  }
  return variable;
}

void checkInterval(int intervalBegin, int intervalEnd) {
  if (intervalBegin > intervalEnd) {
    fprintf(stderr, "Invalid interval: begin (%d) > end (%d)\n", intervalBegin,
            intervalEnd);
    abort();
  }
}

void fillArray(int *arr, size_t arr_size) {
  int choice = 0;
  printf("Enter 1 for random filling\nEnter 2 for manual filling\nEnter your "
         "choice: ");
  if (scanf("%d", &choice) != 1) {
    fprintf(stderr, "Failed to read fill choice from input\n");
    abort();
  }
  if (choice == randomFill) {
    feelRandomNumbers(arr, arr_size);
  } else if (choice == manualFill) {
    readNumbersFromStdin(arr, arr_size);
  } else {
    fprintf(stderr, "Invalid fill choice: %d\n", choice);
    abort();
  }
}
