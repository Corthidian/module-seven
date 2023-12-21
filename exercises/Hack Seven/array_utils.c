#include <stdbool.h>
#include <stdio.h>

bool contains(const int *arr, int size, int x) {
    if (arr == NULL || size <= 0) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return true;
        }
    }

    return false;
}

bool containsWithin(const int *arr, int size, int x, int i, int j) {
    for (int index = i; index <= j; index++) {
        if (arr[index] == x) {
            return true;
        }
    }

    return false;
}

