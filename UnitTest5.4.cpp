#include "pch.h"
#include "CppUnitTest.h"
#include "../pr.5.4/MyMath.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest7
{
    TEST_CLASS(UnitTest7)
    {
    public:
        static constexpr double EPS = 1e-9;

        // Усі п'ять способів мають дати очікуване значення
        void CheckAll(int K, int N, double expected)
        {
            Assert::AreEqual(expected, S0(K, N), EPS);
            Assert::AreEqual(expected, S1(K, N, K), EPS);
            Assert::AreEqual(expected, S2(K, N, N), EPS);
            Assert::AreEqual(expected, S3(K, N, K, 0), EPS);
            Assert::AreEqual(expected, S4(K, N, N, 0), EPS);
        }

        // Усі п'ять способів мають збігатися між собою
        void CheckConsistent(int K, int N)
        {
            double r = S0(K, N);
            Assert::AreEqual(r, S1(K, N, K), EPS);
            Assert::AreEqual(r, S2(K, N, N), EPS);
            Assert::AreEqual(r, S3(K, N, K, 0), EPS);
            Assert::AreEqual(r, S4(K, N, N, 0), EPS);
        }

        TEST_METHOD(TestF_1_1)
        {
            Assert::AreEqual(2.0, f(1, 1), EPS);
        }

        TEST_METHOD(TestF_4_2)
        {
            Assert::AreEqual(0.375, f(4, 2), EPS);
        }

        TEST_METHOD(TestN1)
        {
            CheckAll(1, 1, 2.0);
        }

        TEST_METHOD(TestN2)
        {
            CheckAll(1, 2, 2.0);  // 1.5 + 0.5
        }

        TEST_METHOD(TestN3)
        {
            // 4/3 + 5/12 + 2/9
            CheckAll(1, 3, 1.3333333333333333 + 0.4166666666666667 + 0.2222222222222222);
        }

        TEST_METHOD(TestSingleTerm)
        {
            CheckAll(2, 2, 0.5);
        }

        TEST_METHOD(TestPartialRange)
        {
            CheckAll(2, 3, 0.4166666666666667 + 0.2222222222222222);
        }

        TEST_METHOD(TestConsistent_1_10)
        {
            CheckConsistent(1, 10);
        }

        TEST_METHOD(TestConsistent_3_17)
        {
            CheckConsistent(3, 17);
        }

        TEST_METHOD(TestConsistent_1_1000)
        {
            CheckConsistent(1, 1000);
        }
    };
}