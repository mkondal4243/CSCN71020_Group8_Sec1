#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" void calculateTriangleAngles(const int* sides, double* angles);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestEquilateralTriangleFunctionality)
		{
			int sides[3] = { 5, 5, 5 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Equilateral triangle");
		}

		TEST_METHOD(TestIsoscelesTriangleFunctionality)
		{
			
			int sides[3] = { 7, 7, 10 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Isosceles triangle");
		}

		TEST_METHOD(TestScaleneTriangleFunctionality)
		{
			int sides[3] = { 3, 4, 5 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Scalene triangle");
		}

		TEST_METHOD(TestInvalidTriangleFunctionality)
		{
			int sides[3] = { 1, 1, 2 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Not a triangle");
		}

		TEST_METHOD(TestCalculateTriangleAnglesEquilateral)
		{
			
			int sides[3] = { 5, 5, 5 };
			double angles[3] = { 0.0, 0.0, 0.0 }; 

			calculateTriangleAngles(sides, angles);

			Assert::AreEqual(angles[0], 60.0); 
			Assert::AreEqual(angles[1], 60.0);
			Assert::AreEqual(angles[2], 60.0);
			
		}

		TEST_METHOD(TestCalculateTriangleAnglesIsosceles)
		{
			int sides[3] = { 7, 7, 10 };
			double angles[3] = { 0, 0, 0 };

			calculateTriangleAngles(sides, angles);

			Assert::AreEqual(angles[0], 44.0, 0.01); // Adjust the epsilon as needed
			Assert::AreEqual(angles[1], 44.0, 0.01);
			Assert::AreEqual(angles[2], 91.0, 0.01);
			
		}

		TEST_METHOD(TestCalculateTriangleAnglesScalene)
		{
			int sides[3] = { 3, 4, 5 };
			double angles[3] = { 0, 0, 0 };

			calculateTriangleAngles(sides, angles);

			Assert::AreEqual(angles[0], 37.0, 0.01); 
			Assert::AreEqual(angles[1], 53.0, 0.01);
			Assert::AreEqual(angles[2], 90.0, 0.01);
		}
	};
}
