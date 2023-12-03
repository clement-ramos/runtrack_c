#ifndef MANHATTAN_H
#define MANHATTAN_H

typedef struct {
    int x;
    int y;
} point;

// Macro to compute the absolute value of a number
#define ABS(x) ((x) < 0 ? -(x) : (x))

// Prototype
int manhattan_distance(point p1, point p2);

#endif /* MANHATTAN_H */
