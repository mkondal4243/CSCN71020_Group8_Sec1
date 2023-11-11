#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

RECTANGLE_POINT* getRectanglePoints(RECTANGLE_POINT* points) {


	printf("Enter the coordinates of four points:\n");
	for (int i = 0; i < 4; i++) {
		printf("Point %d:\n", i + 1);
		printf("x-coordinate: ");
		scanf_s("%d", &points[i].x);
		printf("y-coordinate: ");
		scanf_s("%d", &points[i].y);
	}


	return points;
}