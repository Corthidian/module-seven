#include <stdlib.h>
#include <stdio.h>

#include "array_utils.h"

void printArray(const int *arr, int n) {
  if (arr == NULL) {
    printf("[null]\n");
    return;
  }
  printf("[ ");
  for (int i = 0; i < n - 1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d ]\n", arr[n - 1]);
}

void printTable(int **table, int n, int m) {
  if (table == NULL) {
    printf("[null]\n");
    return;
  }
  for (int i = 0; i < n; i++) {
    printArray(table[i], m);
  }
}

int *generateRandomArray(int size) {
  if (size < 0) {
    return NULL;
  }

  int *randomArr = (int *)malloc(sizeof(int) * size);

  if (randomArr == NULL) {
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    randomArr[i] = rand() % 100;
  }

  return randomArr;
}

int getSum(int *arr, int size) {
  if (arr == NULL) {
    return 0;
  }
  int total = 0;
  for (int i = 0; i < size; i++) {
    total += arr[i];
    arr[i] = 0;
  }
  return total;
}

void freeTable(int **table, int n) {
  if (table == NULL) {
    return;
  }
  for (int i = 0; i < n; i++) {
    free(table[i]);
  }
  free(table);
}

double getMean(const int *arr, int size) {
  if (arr == NULL || size <= 0) {
    return 0.0;
  }

  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  return (double)sum / size;
}

int getMin(const int *arr, int size) {
  if (arr == NULL || size <= 0) {
    return 0; // Return a default value; modify accordingly
  }

  int min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  return min;
}

int getIndexOfMin(const int *arr, int size) {
  if (arr == NULL || size <= 0) {
    return -1; // Return an error value; modify accordingly
  }

  int min = arr[0];
  int minIndex = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
      minIndex = i;
    }
  }

  return minIndex;
}

int getMax(const int *arr, int size) {
  if (arr == NULL || size <= 0) {
    return 0; // Return a default value; modify accordingly
  }

  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  return max;
}

int getIndexOfMax(const int *arr, int size) {
  if (arr == NULL || size <= 0) {
    return -1; // Return an error value; modify accordingly
  }

  int max = arr[0];
  int maxIndex = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
      maxIndex = i;
    }
  }

  return maxIndex;
}

int *filterThreshold(const int *arr, int size, int threshold, int *resultSize) {
  if (arr == NULL || size <= 0 || resultSize == NULL) {
    *resultSize = 0;
    return NULL; // Return an error value; modify accordingly
  }

  // Count elements greater than or equal to the threshold
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] >= threshold) {
      count++;
    }
  }

  // Allocate memory for the filtered array
  int *filteredArr = (int *)malloc(sizeof(int) * count);
  if (filteredArr == NULL) {
    *resultSize = 0;
    return NULL; // Memory allocation failed; modify accordingly
  }

  // Copy elements greater than or equal to the threshold
  int index = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] >= threshold) {
      filteredArr[index++] = arr[i];
    }
  }

  *resultSize = count;
  return filteredArr;
}

int **createMultiplicationTable(int n, int m) {
  if (n <= 0 || m <= 0) {
    return NULL; // Return an error value; modify accordingly
  }

  // Allocate memory for the 2D array
  int **table = (int **)malloc(sizeof(int *) * n);
  if (table == NULL) {
    return NULL; // Memory allocation failed; modify accordingly
  }

  for (int i = 0; i < n; i++) {
    table[i] = (int *)malloc(sizeof(int) * m);
    if (table[i] == NULL) {
      // Memory allocation failed; free allocated memory and return NULL
      for (int j = 0; j < i; j++) {
        free(table[j]);
      }
      free(table);
      return NULL;
    }

    // Fill in the multiplication table values
    for (int j = 0; j < m; j++) {
      table[i][j] = (i + 1) * (j + 1);
    }
  }

  return table;
}
