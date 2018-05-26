#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EngineTest
{		
	using namespace MiniEngineLib;

	TEST_CLASS(VectorTest)
	{
	public:
		
		TEST_METHOD(VectorCreationTest)
		{
			Vector<int> intVector1 = Vector<int>(0, 1, 2);

			Assert::AreEqual(intVector1._x, 0);
			Assert::AreEqual(intVector1._y, 1);
			Assert::AreEqual(intVector1._z, 2);

			Vector<int> intVector2 = Vector<int>(-1, -2, -3);

			Assert::AreEqual(intVector2._x, -1);
			Assert::AreEqual(intVector2._y, -2);
			Assert::AreEqual(intVector2._z, -3);

			Vector<float> floatVector1 = Vector<float>(1.0f, 2.5f, 0.0f);

			Assert::AreEqual(floatVector1._x, 1.0f);
			Assert::AreEqual(floatVector1._y, 2.5f);
			Assert::AreEqual(floatVector1._z, 0.0f);

			Vector<float> floatVector2 = Vector<float>(-1.0f, -2.5f, -0.0f);

			Assert::AreEqual(floatVector2._x, -1.0f);
			Assert::AreEqual(floatVector2._y, -2.5f);
			Assert::AreEqual(floatVector2._z, -0.0f);
		}

		TEST_METHOD(VectorOperatorPlusTest)
		{
			Vector<int> intVector1 = Vector<int>(1, 2, 3);
			Vector<int> intVector2 = Vector<int>(3, 4, 5);
			Vector<int> intPlusVector = intVector1 + intVector2;

			Assert::AreEqual(intPlusVector._x, 1 + 3);
			Assert::AreEqual(intPlusVector._y, 2 + 4);
			Assert::AreEqual(intPlusVector._z, 3 + 5);
		}
	};
}