#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"



// Function to analyze the type of triangle based on their side lengths
char* analyzeTriangle(int side1, int side2, int side3) {
	if (side1 + side2 <= side3 ||
		side1 + side3 <= side2 ||
		side2 + side3 <= side1) {
		return "Not a triangle";
	}
    // Check for an equilateral triangle 
    else if (side1 == side2 && side1 == side3) {
        return "Equilateral triangle";
    }
    // Check for an isosceles triangle
    else if ((side1 == side2 && side1 != side3) ||
        (side1 == side3 && side1 != side2) ||
        (side2 == side3 && side2 != side1))
    {
        return "Isosceles triangle";
    }
    //Scalene triangle 
    else 
    {
        return "Scalene triangle";
    }
}
// Function to classify the type of triangle in terms of array size lengths
char* classifyTriangle(const int* sides) {
    // Check for types of triangle 
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

// Function to calculate the angles of a triangle based on their side lengths
void calculateTriangleAngles(const int* sides, double* angles) {
    double a = sides[0];
    double b = sides[1];
    double c = sides[2];

    // Use the law of cosines to calculate each angle
    angles[0] = acos((b * b + c * c - a * a) / (2 * b * c)) * (180.0 / 3.14);
    angles[1] = acos((a * a + c * c - b * b) / (2 * a * c)) * (180.0 / 3.14);
    angles[2] = 180 - angles[0] - angles[1];

    // Round the angles to the nearest integer
    angles[0] = round(angles[0]);
    angles[1] = round(angles[1]);
    angles[2] = round(angles[2]);
}