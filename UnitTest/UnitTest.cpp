#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" void calculateTriangleAngles(const int* sides, double* angles);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestTriangle)
	{
	public:
		
		//Tests for Equilateral Triangle
		TEST_METHOD(TestEquilateralTriangleFunctionality)  
		{
			int sides[3] = { 5, 5, 5 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Equilateral triangle");
		}

		TEST_METHOD(TestEquilateralTriangleDecimalFunctionality)  
		{
			int sides[3] = { 3.5, 3.5, 3.5 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Equilateral triangle");
		}

		TEST_METHOD(TestEquilateralTriangleLargerValFunctionality)
		{
			int sides[3] = { 10, 10, 10 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Equilateral triangle");
		}

		//tests for isoceles triangle 
		TEST_METHOD(TestIsoscelesTriangleFunctionality)
		{
			
			int sides[3] = { 7, 7, 10 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Isosceles triangle");
		}

		TEST_METHOD(TestIsoscelesTriangleDecimalFunctionality)
		{
			int sides[3] = { 5.5, 5.5, 7 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Isosceles triangle");
		}

		TEST_METHOD(TestIsoscelesTriangleLargerValFunctionality)
		{
			int sides[3] = { 8, 8, 10 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Isosceles triangle");
		}


		//tests for scalene triangle 
		TEST_METHOD(TestScaleneTriangleFunctionality)
		{
			int sides[3] = { 3, 4, 5 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Scalene triangle");
		}

		TEST_METHOD(TestScaleneTriangleDecimalValuesFunctionality)
		{
			int sides[3] = { 2.5, 3.5, 4.5 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Scalene triangle");
		}

		TEST_METHOD(TestScaleneTriangleLargerValFunctionality)
		{
			int sides[3] = { 7, 10, 12 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Scalene triangle");
		}

		//invalid test cases 
		TEST_METHOD(TestInvalidTriangleFunctionality)  
		{
			int sides[3] = { 1, 1, 2 };

			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);

			Assert::AreEqual(result, "Not a triangle");
		}


		TEST_METHOD(TestInvalidNegativeSideLengths) 
		{
			int sides[3] = { -3, 4, 5 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Not a triangle");
		}

		TEST_METHOD(TestInvalidZeroSideLengths) 
		{
			int sides[3] = { 0, 4, 5 };
			char* result = analyzeTriangle(sides[0], sides[1], sides[2]);
			Assert::AreEqual(result, "Not a triangle");
		}

		//angles test cases 
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

			Assert::AreEqual(angles[0], 44.0, 0.01); 
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

		TEST_METHOD(TestSumOfAngles)  
		{
			int sides[3] = { 3, 4, 5 };
			double angles[3] = { 0, 0, 0 };
			calculateTriangleAngles(sides, angles);
			Assert::AreEqual(angles[0] + angles[1] + angles[2], 180.0, 0.01);
		}

	};
}
