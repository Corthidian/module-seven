#include "image_utils.h"
#include <stdio.h>
#include <stdlib.h>

//a single pixel:
double Pixel p;
//an array of n pixels:
Pixel *p = (Pixel *) malloc(sizeof(Pixel) * n);

//swap two pixels:
Pixel a, b;

Pixel temp = a;
a = b;
b = temp;
double rotated, copy;


Pixel **copyImage(const Pixel **image, int height, int width) {
    Pixel **copy = allocateImage(height, width);

    if (copy == NULL) {
        return NULL;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j] = image[i][j];
        }
    }

    return copy;
}

void flipHorizontal(Pixel **image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            Pixel temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

void flipVertical(Pixel **image, int height, int width) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            Pixel temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

Pixel **rotateClockwise(const Pixel **image, int height, int width) {
    Pixel **rotated = allocateImage(width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            rotated[j][height - i - 1] = image[i][j];
        }
    }

    return rotated;
}
