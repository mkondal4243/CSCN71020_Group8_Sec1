#pragma once
#include <stdbool.h>
typedef struct Point {
	int x;
	int y;
}POINT;
typedef struct Lines {
	POINT s; // s is for starting point
    POINT e; // e is for ending point
}LINES;

POINT* getRectanglePoints(POINT* points);
int isRectangle(LINES lines[4]);
double distance(POINT p1, POINT p2);
double AreaOfRectangle(LINES lines[]);
double PerimeterOfRectangle(LINES lines[]);