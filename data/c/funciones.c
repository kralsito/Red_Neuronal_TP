#include <stdio.h>

struct Point {
    int x;
    int y;
};

void printPoint(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

int main() {
    struct Point point1 = {2, 3};
    struct Point point2 = {5, 8};
    printf("Point 1: ");
    printPoint(point1);
    printf("Point 2: ");
    printPoint(point2);
    return 0;
}
