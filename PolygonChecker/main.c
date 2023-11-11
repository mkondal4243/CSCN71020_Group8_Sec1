#include <stdio.h>
#include <stdbool.h>

#include <math.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"


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
			if (isTriangle(triangleSidesPtr)) {
				double angles[3];
				calculateTriangleAngles(triangleSidesPtr, angles);
				printf_s("The three inside angles of the triangle are:\n");
				printf_s("Angle 1: %.2lf degrees\n", angles[0]);
				printf_s("Angle 2: %.2lf degrees\n", angles[1]);
				printf_s("Angle 3: %.2lf degrees\n", angles[2]);
				// Determine and print the type of triangle
				printf_s("Type of triangle: %s\n", classifyTriangle(triangleSidesPtr));
			}
			else {
				printf_s("The given side lengths do not form a triangle.\n");
			}
			break;
		 //case for rectangle 
			
			
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
