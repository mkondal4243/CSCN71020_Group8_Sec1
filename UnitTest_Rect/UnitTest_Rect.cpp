#include "pch.h"
#include "CppUnitTest.h" 
#include "Header.h"
#define RECTSIDES 4
extern "C" int isRectangle(LINES lines[]);
extern "C" void createRectangleLines(POINT * points, LINES * rectangle);
extern "C" double distance(POINT p1, POINT p2);
extern "C" double AreaOfRectangle(LINES lines[]);
extern "C" double PerimeterOfRectangle(LINES lines[]);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRect
{
	TEST_CLASS(UnitTestRect)
	{
	public:
		
		TEST_METHOD(FunctionalityTest1)
		{
			int expected = 1;
			POINT point[RECTSIDES] = {{0, 0},{0, 2}, {3, 2}, {3, 0}};
			LINES rectangle[RECTSIDES];
		     createRectangleLines(point ,rectangle);
			 int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(FunctionalityTest2)
		{
			int expected = 1;
			POINT point[RECTSIDES] = { {-4, -5},{ -4, -2 },{ -1, -2 }, { -1, -5 } };
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}   

		TEST_METHOD(FunctionalityTest3)
		{
			int expected = 1;
			POINT point[RECTSIDES] = { {1, -5}, { 7, -5 }, { 7, -2 }, { 1, -2 } };
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
           int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}
	
		TEST_METHOD(FunctionalityTest4)
		{
			int expected = 1;
			POINT point[RECTSIDES] = { {-1000,500}, {1000,500}, {1000,-500}, { -1000,-500} };
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(ExpectionalTest1)
		{
			int expected = 1;
			POINT point[RECTSIDES] = { {1, 3}, {6, 3}, {6, 6}, {5, 6} };
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
			int res = isRectangle(rectangle);
			Assert::AreNotEqual(res, expected);
		}

		TEST_METHOD(ExpectionalTest2)
		{
			int expected = 1;
			POINT point[RECTSIDES] = { {50, 76}, {99, 50}, {98, 50}, {55, 60} };
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
			int res = isRectangle(rectangle);
			Assert::AreNotEqual(res, expected);
		}

		TEST_METHOD(DistanceTest1)
		{
			double expected = 10.295630140987;
			POINT p1 = { 13,10 }, p2 = { 4,5 };
		     double dis=distance(p1, p2);
			Assert::AreEqual(expected,dis);
		}

		TEST_METHOD(DistanceTest2)
		{
			int expected = 11;
			POINT p1 = { -9,-5 }, p2 = { -3,5 };
			int dis = distance(p1, p2);
			Assert::AreEqual(expected, dis);
		}

		TEST_METHOD(FailDistanceTest1)
		{
			double expected = 11;
			POINT p1 = { -9,-5 }, p2 = { -3,5 };
			double dis = distance(p1, p2);
			Assert::AreNotEqual(expected, dis);
		}
		TEST_METHOD(FailDistanceTest2)
		{
			double expected = 179.40178371466;
			POINT p1 = { -100,7 }, p2 = { 79,-5 };
			double dis = distance(p1, p2);
			Assert::AreNotEqual(expected, dis);
		}
		TEST_METHOD(AreaFunctionalTest1)
		{
			double expected = 55.47071299343465;
			POINT point[RECTSIDES] = { {50, 76}, {99, 50}, {98, 50}, {55, 60} };
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
			int res = isRectangle(rectangle);
			double area= AreaOfRectangle(rectangle);
			Assert::AreEqual(area, expected);
		}
		TEST_METHOD(AreaFunctionalTest2)
		{
			double expected = 60;
			POINT point[RECTSIDES] = {{-5, 10}, {7, 10}, {7, 5}, {-5, 5}};
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
			int res = isRectangle(rectangle);
			double area = AreaOfRectangle(rectangle);
			Assert::AreEqual(area, expected);
		}
		TEST_METHOD(FailAreaTest1)
		{
			double expected = 4000001;// actual value 4000000
			POINT point[RECTSIDES] = { {3000, 4000}, {5000, 4000}, {5000, 6000}, {3000, 6000} };
			LINES rectangle[RECTSIDES];
			createRectangleLines(point, rectangle);
			int res = isRectangle(rectangle);
			double area = AreaOfRectangle(rectangle);
			Assert::AreNotEqual(area, expected);
		}
			TEST_METHOD(FailAreaTest2)
			{
				double expected = 801;//actual value 800
				POINT point[RECTSIDES] = { {-30, 50}, {10, 50}, {10, 70}, {-30, 70} };
				LINES rectangle[RECTSIDES];
				createRectangleLines(point, rectangle);
				int res = isRectangle(rectangle);
				double area = AreaOfRectangle(rectangle);
				Assert::AreNotEqual(area, expected);
		    }
			TEST_METHOD(PerimeterFunctionalityTest1)
			{
				double expected = 40;
				POINT point[RECTSIDES] = { {15, 20}, {25, 20}, {25, 30}, {15, 30} };
				LINES rectangle[RECTSIDES];
				createRectangleLines(point, rectangle);
				int res = isRectangle(rectangle);
				double perimeter = PerimeterOfRectangle(rectangle);
				Assert::AreEqual(perimeter, expected);
			}
			TEST_METHOD(PerimeterFunctionalityTest2)
			{
				double expected = 80;
				POINT point[RECTSIDES] = { {30, 40}, {50, 40}, {50, 60}, {30, 60} };
                LINES rectangle[RECTSIDES];
				createRectangleLines(point, rectangle);
				int res = isRectangle(rectangle);
				double perimeter = PerimeterOfRectangle(rectangle);
				Assert::AreEqual(perimeter, expected);
			}
			TEST_METHOD(FailPerimeterTest1)
			{
				double expected = 60;//actual value 600
				POINT point[RECTSIDES] = { {150, 250}, {300, 250}, {300, 400}, {150, 400} };
				LINES rectangle[RECTSIDES];
				createRectangleLines(point, rectangle);
				int res = isRectangle(rectangle);
				double perimeter = PerimeterOfRectangle(rectangle);
				Assert::AreNotEqual(perimeter, expected);
			}
			TEST_METHOD(FailPerimeterTest2)
			{
				double expected = 22;//actual value 22000
				POINT point[RECTSIDES] = { {12000, 15000}, {18000, 15000}, {18000, 20000}, {12000, 20000} };
				LINES rectangle[RECTSIDES];
				createRectangleLines(point, rectangle);
				int res = isRectangle(rectangle);
				double perimeter = PerimeterOfRectangle(rectangle);
				Assert::AreNotEqual(perimeter, expected);
			}
	};
}