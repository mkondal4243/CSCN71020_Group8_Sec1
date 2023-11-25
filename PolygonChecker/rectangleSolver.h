#pragma once
#include <stdbool.h>
typedef struct Point {
    int x;
    int y;
} POINT;

typedef struct {
    POINT s; // Start point
    POINT e; // End point
} LINES;

POINT* getRectanglePoints(POINT* points);
void createRectangleLines(POINT* points, LINES* rectangle);
int isRectangle(LINES lines[]);
double distance(POINT p1, POINT p2);
double AreaOfRectangle(LINES lines[]);
double PerimeterOfRectangle(LINES lines[]);