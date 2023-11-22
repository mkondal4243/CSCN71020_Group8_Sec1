#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#define RECTSIDES 4
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define RECTSIDES 4



// Function to read value from the user
POINT* getRectanglePoints(POINT* points) {
    printf("Enter the coordinates of four points:\n");
    for (int i = 0; i < RECTSIDES; i++) {
        printf("Point %d:\n", i + 1);
        printf("x-coordinate: ");
        int numparse = scanf_s("%d", &points[i].x);
        if (numparse == 0)
            exit(EXIT_FAILURE);
        printf("y-coordinate: ");
        int numparse1 = scanf_s("%d", &points[i].y);
        if (numparse1 == 0)
            exit(EXIT_FAILURE);
    }
    return points;
}

// Function to check if the given lines form a rectangle
int isRectangle(LINES lines[]) {
    // Check if the opposite sides have equal lengths
    
        int  d1 = distance(lines[0].s, lines[0].e); // assuming the first the co-ordinates is length
        int  d2 = distance(lines[2].s, lines[2].e); // oppsite side
        int  d3= distance(lines[1].s, lines[1].e); // assumig the second co-orrdinates is width
        int  d4= distance(lines[3].s, lines[3].e); // oppsite side
        if(((d1==d2)&&(d3==d4))||((d2==d3)&&(d1==d4)))
        return 1; // It's a rectangle
        return 0;//not a rectangle
}

// Function to calculate the distance between two points
double distance(POINT p1, POINT p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to find the area of the rectangle
double AreaOfRectangle(LINES lines[]) {
    // Assuming lines[0] and lines[1] represent the length and width
    double length = distance(lines[0].s, lines[0].e);
    double width = distance(lines[1].s, lines[1].e);
    return length * width;
}

// Function to find the perimeter of the rectangle
double PerimeterOfRectangle(LINES lines[]) {
    double perimeter = 0.0;

    for (int i = 0; i < RECTSIDES; i++) {
        perimeter += distance(lines[i].s, lines[i].e);
    }

    return perimeter;
}

