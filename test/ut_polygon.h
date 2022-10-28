#include <gtest/gtest.h>
#include "../src/Polygon.h"

class PolygonTest : public ::testing ::Test
{
protected:
    MathVector *ptr = nullptr;
    MathVector v1;
    MathVector v2;
    MathVector v3;
    Polygon p1;
    void SetUp() override;
    void TearDown() override;
};

void PolygonTest::SetUp()
{
    double arr1[2] = {0, 0};
    double arr2[2] = {3, 0};
    double arr3[2] = {0, 4};

    v1 = MathVector(2, arr1);
    v2 = MathVector(2, arr2);
    v3 = MathVector(2, arr3);

    MathVector *ptr = new MathVector[3];
    ptr[0] = v1;
    ptr[1] = v2;
    ptr[2] = v3;

    p1 = Polygon(ptr, 3);
}

void PolygonTest::TearDown()
{
    delete[] ptr;
}

TEST_F(PolygonTest, Perimeter)
{
    ASSERT_EQ(12, p1.perimeter());
}

// TEST(POLYGON, Perimeter)
// {
//     double arr1[2] = {0, 0};
//     double arr2[2] = {3, 0};
//     double arr3[2] = {0, 4};

//     MathVector v1(2, arr1);
//     MathVector v2(2, arr2);
//     MathVector v3(2, arr3);

//     MathVector *ptr = new MathVector[3];
//     ptr[0] = v1;
//     ptr[1] = v2;
//     ptr[2] = v3;

//     Polygon p1(ptr, 3);
//     delete[] ptr;
//     ASSERT_EQ(12, p1.perimeter());
// }