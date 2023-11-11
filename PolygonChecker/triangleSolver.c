#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}
// Function to classify the type of triangle
char* classifyTriangle(const int* sides) {
	if (sides[0] == sides[1] && sides[1] == sides[2]) {
		return "Equilateral";
	}
	else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2]) {
		return "Isosceles";
	}
	else {
		return "Scalene";
	}
}