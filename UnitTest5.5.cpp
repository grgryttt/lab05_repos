#include "pch.h"
#include "CppUnitTest.h"
#include "../PR.5.5/MyMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
    TEST_CLASS(UnitTest55)
    {
    public:
        int Run(int n)
        {
            int depth = 0;
            return f(n, 0, depth);
        }

        int Depth(int n)
        {
            int depth = 0;
            f(n, 0, depth);
            return depth;
        }

        TEST_METHOD(TestN1) { Assert::AreEqual(1, Run(1)); }
        TEST_METHOD(TestN2) { Assert::AreEqual(1, Run(2)); }
        TEST_METHOD(TestN3) { Assert::AreEqual(3, Run(3)); }
        TEST_METHOD(TestN4) { Assert::AreEqual(1, Run(4)); }
        TEST_METHOD(TestN5) { Assert::AreEqual(3, Run(5)); }
        TEST_METHOD(TestN6) { Assert::AreEqual(5, Run(6)); }
        TEST_METHOD(TestN7) { Assert::AreEqual(7, Run(7)); }
        TEST_METHOD(TestN10) { Assert::AreEqual(5, Run(10)); }

        TEST_METHOD(TestDepthN1) { Assert::AreEqual(0, Depth(1)); }
        TEST_METHOD(TestDepthN3) { Assert::AreEqual(1, Depth(3)); }
        TEST_METHOD(TestDepthN10) { Assert::AreEqual(3, Depth(10)); }  // 10 -> 5 -> 2 -> 1
    };
}