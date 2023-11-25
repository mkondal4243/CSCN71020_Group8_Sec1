//main.c

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
		case 1://case for triangle 
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2: // case for rectangle
			POINT rectangle_points[RECTSIDES];
			LINES rectangle[RECTSIDES];
			getRectanglePoints(rectangle_points);
			createRectangleLines(rectangle_points, rectangle);
			int res = isRectangle(rectangle);
			if (res) {
				printf("The shape is a rectangle.\n");
				printf("The rectangle has an Area: %.6f, Perimeter: %.6f\n", AreaOfRectangle(rectangle), PerimeterOfRectangle(rectangle));
			}
			else {
				printf("The given points do not form a rectangle.\n");
			}
			break;
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
//ask user to enter 3 sides of triangle 
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


