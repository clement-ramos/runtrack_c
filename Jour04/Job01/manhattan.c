#include <stdio.h>
#include "manhattan.h"

// Implementation of the manhattan_distance function
int manhattan_distance(point p1, point p2) {
    int dx = ABS(p1.x - p2.x);
    int dy = ABS(p1.y - p2.y);
    
    return dx + dy;
}

// int main() {
//     // Create two points
//     point p1 = {2, 3};
//     point p2 = {5, 7};

//     int distance = manhattan_distance(p1, p2);

//     // Print the result
//     printf("La distance de Manhattan entre les points (%d, %d) et (%d, %d) est : %d\n",
//            p1.x, p1.y, p2.x, p2.y, distance);

//     return 0;
// }