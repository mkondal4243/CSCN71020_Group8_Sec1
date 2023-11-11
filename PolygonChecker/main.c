#include <stdio.h>
#include <stdbool.h>

#include <math.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#define RECTSIDES 4


int side = 0;

int main() {

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2: // case for rectangle
			printf_s("Rectangle selected.\n");
			POINT  rectangle_points[4] ;
			POINT *rectangle_pointsPtr = getRectanglePoints(rectangle_points);
			for (int i = 0; i < 4; i++) {
				printf("Point %d: x = %d, y = %d\n", i + 1,rectangle_pointsPtr[i].x, rectangle_pointsPtr[i].y);
			}
			LINES line[RECTSIDES];

			line[0].s = rectangle_pointsPtr[0];
			line[0].e = rectangle_pointsPtr[1];

			line[1].s = rectangle_pointsPtr[1];
			line[1].e = rectangle_pointsPtr[2];

			line[2].s = rectangle_pointsPtr[2];
			line[2].e = rectangle_pointsPtr[3];

			line[3].s = rectangle_pointsPtr[3];
			line[3].e = rectangle_pointsPtr[1];

			int res= isRectangle(line);
			if (res) {
				printf_s("%s\n", "The rectangle is made");
				double PERIMETER = AreaOfRectangle(line);
				double AREA = AreaOfRectangle(line);
				printf_s(" The rectangle is made has a Area : %2f , perimeter : %2f" ,AREA,PERIMETER);
			}
			else
				printf_s("%s\n", "can't make a rectangle");
			
			
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");         //rectangle option
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}
bool isTriangle(const int* sides) {
	// Check the triangle inequality theorem
	return (sides[0] + sides[1] > sides[2]) &&
		(sides[0] + sides[2] > sides[1]) &&
		(sides[1] + sides[2] > sides[0]);
}

void calculateTriangleAngles(const int* sides, double* angles) {
	// Use the law of cosines to calculate angles
	for (int i = 0; i < 3; i++) {
		angles[i] = acos((sides[(i + 1) % 3] * sides[(i + 1) % 3] +
			sides[(i + 2) % 3] * sides[(i + 2) % 3] -
			sides[i] * sides[i]) /
			(2.0 * sides[(i + 1) % 3] * sides[(i + 2) % 3]));
		angles[i] = angles[i] * (180.0 / 3.14); // Convert to degrees
	}
}
