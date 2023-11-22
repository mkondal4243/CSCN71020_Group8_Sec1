#include "pch.h"
#include "CppUnitTest.h" 
#include "Header.h"
extern "C" int isRectangle(LINES lines[]);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRect
{
	TEST_CLASS(UnitTestRect)
	{
	public:
		
		TEST_METHOD(FunctionalityTest1)
		{
			int expected = 1;
			LINES rectangle[] = {
				{{0, 0}, {0, 2}},
				{{0, 2}, {3, 2}},
				{{3, 2}, {3, 0}},
				{{3, 0}, {0, 0}}
			};
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(FunctionalityTest2)
		{
			int expected = 1;
			LINES rectangle[] = {
				{-4, -5}, {-4, -2},
				{-4, -2}, {-1, -2},
				{-1, -2}, {-1, -5},
				{-1, -5}, {-4, -5}
			};

			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(FunctionalityTest3)
		{
			int expected = 1;
			LINES rectangle[] = {
				{1, -5}, {7, -5},
				{7, -5}, {7, -2},
				{7, -2}, {1, -2},
				{1, -2}, {1, -5}
			};

			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(ExpectionalTest1)
		{
			int expected = 0;
			LINES rectangle[] = {
				{{1, 1}, {0, 2}},
				{{0, 2}, {8, 4}},
				{{3, 4}, {3, 0}},
				{{3, 0}, {5, 0}}
			};
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(ExpectionalTest2)
		{
			int expected = 1;
			LINES rectangle[] = {
				{{0, 0}, {0, 2}},
				{{0, 2}, {3, 2}},
				{{3, 2}, {3, 0}},
				{{3, 0}, {0, 0}}
			};
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(ExpectionalTest3)
		{
			int expected = 0;
			LINES rectangle[] = {
				{{0, 0}, {0, 2}},
				{{0, 2}, {3, 9}},
				{{3, 2}, {3, 0}},
				{{3, 0}, {0, 0}}
			};
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(BoundaryTest1)
		{
			int expected = 1;
			LINES rectangle[] = {
				{{0, 0}, {0, 2}},
				{{0, 2}, {3, 2}},
				{{3, 2}, {3, 0}},
				{{3, 0}, {0, 0}}
			};
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(BoundaryTest2)
		{
			int expected = 1;
			LINES rectangle[] = {
				{{0, 0}, {0, 2}},
				{{0, 2}, {3, 2}},
				{{3, 2}, {3, 0}},
				{{3, 0}, {0, 0}}
			};
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}

		TEST_METHOD(BoundaryTest3)
		{
			int expected = 1;
			LINES rectangle[] = {
				{{0, 0}, {0, 2}},
				{{0, 2}, {3, 2}},
				{{3, 2}, {3, 0}},
				{{3, 0}, {0, 0}}
			};
			int res = isRectangle(rectangle);
			Assert::AreEqual(expected, res);
		}
	};
}
