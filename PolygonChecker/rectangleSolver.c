#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#define RECTSIDES 4
//Function to read value from the user
POINT* getRectanglePoints(POINT* points) {

printf("Enter the coordinates of four points:\n");
	for (int i = 0; i < RECTSIDES; i++) {
		printf("Point %d:\n", i + 1);
		printf("x-coordinate: ");
		scanf_s("%d", &points[i].x);
		printf("y-coordinate: ");
		scanf_s("%d", &points[i].y);
	}
  return points;

}


// Function to check if the given lines form a rectangle
int isRectangle(LINES lines[RECTSIDES]) {
	// Check if the opposite sides have equal lengths
	for (int i = 0; i < RECTSIDES; i++) {
		int j = (i + 2) % RECTSIDES; // Index of the opposite side
		if (distance(lines[i].s, lines[i].e) != distance(lines[j].s, lines[j].e)) {
			return 0; // Not a rectangle
		}
	}
	return 1; // It's a rectangle
}


// Function to calculate the distance between two points
double distance(POINT p1, POINT p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}


