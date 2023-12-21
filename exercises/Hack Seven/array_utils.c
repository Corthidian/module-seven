#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



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

int *paddedCopy(const int *arr, int oldSize, int newSize) {
    int *newArr = (int *)malloc(sizeof(int) * newSize);

    if (newArr == NULL) {
        return NULL;
    }

    int minSize = (oldSize < newSize) ? oldSize : newSize;
    for (int i = 0; i < minSize; i++) {
        newArr[i] = arr[i];
    }

    if (newSize > oldSize) {
        for (int i = oldSize; i < newSize; i++) {
            newArr[i] = 0;
        }
    }

    return newArr;
}

void reverse(int *arr, int size) {
    if (arr == NULL || size <= 1) {
        return;
    }

    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

