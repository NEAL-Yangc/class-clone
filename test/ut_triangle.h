#include <gtest/gtest.h>
#include "../src/Triangle.h"

// text fixture    // 繼承  // namespace // Test class
class TriangleTest : public ::testing ::Test // 問問題
{
protected:
    MathVector v1;
    MathVector v2;
    MathVector v3;
    Triangle t;
    void SetUp(void) override; // 我繼承Test來的方法我想自定義override
    void TearDown(void) override;
};

void TriangleTest::SetUp()
{
    double arr1[2] = {0, 0};
    double arr2[2] = {3, 0};
    double arr3[2] = {0, 4};

    v1 = MathVector(2, arr1);
    v2 = MathVector(2, arr2);
    v3 = MathVector(2, arr3);

    t = Triangle(v1, v2, v3);

    // rvalue 傳進來不複製畢竟不更改
    t = Triangle(MathVector(2, arr1), MathVector(2, arr2), MathVector(2, arr3));
}

void TriangleTest::TearDown()
{
}

TEST_F(TriangleTest, Primeter)
{
    ASSERT_NEAR(12, t.perimeter(), 0.01);
}

TEST_F(TriangleTest, Area)
{
    ASSERT_NEAR(6, t.area(), 0.01);
}