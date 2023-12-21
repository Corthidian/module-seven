
#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

typedef struct {
    double red;
    double green;
    double blue;
} Pixel;

Pixel **allocateImage(int height, int width);
void deallocateImage(Pixel **image, int height);

Pixel **copyImage(const Pixel **image, int height, int width);
void flipHorizontal(Pixel **image, int height, int width);
void flipVertical(Pixel **image, int height, int width);
Pixel **rotateClockwise(const Pixel **image, int height, int width);

#endif  
