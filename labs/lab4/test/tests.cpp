#include <gtest/gtest.h>
#include "point.h"
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"
#include "array.h"
#include "figure.h"
#include <cmath>

TEST(TriangleGetCenter, DefaultConstructor) {
    Triangle<int> t;
    ASSERT_TRUE(t.get_center() == Point<int>(0, 0));
}

TEST(TriangleGetCenter, CustomTriangle) {
    Triangle<int> t(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3));
    ASSERT_TRUE(t.get_center() == Point<int>(2, 1));
}

TEST(TriangleArea, ValidTriangle) {
    Triangle<int> t(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3));
    ASSERT_DOUBLE_EQ(static_cast<double>(t), 6.0);
}

TEST(TriangleEquality, EqualTriangles) {
    Triangle<int> t1(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3));
    Triangle<int> t2(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3));
    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleInequality, UnequalTriangles) {
    Triangle<int> t1(Point<int>(0, 0), Point<int>(4, 0), Point<int>(2, 3));
    Triangle<int> t2(Point<int>(1, 1), Point<int>(2, 2), Point<int>(3, 3));
    ASSERT_TRUE(t1 != t2);
}

TEST(HexagonGetCenter, DefaultConstructor) {
    Hexagon<int> h;
    ASSERT_TRUE(h.get_center() == Point<int>(0, 0));
}

TEST(HexagonGetCenter, CustomHexagon) {
    Hexagon<int> h(Point<int>(0, 0), Point<int>(2, 0), Point<int>(3, 1),
                   Point<int>(2, 2), Point<int>(0, 2), Point<int>(-1, 1));
    ASSERT_TRUE(h.get_center() == Point<int>(1, 1));
}

TEST(HexagonArea, ValidHexagon) {
    Hexagon<int> h(Point<int>(0, 0), Point<int>(2, 0), Point<int>(3, 1),
                   Point<int>(2, 2), Point<int>(0, 2), Point<int>(-1, 1));
    ASSERT_DOUBLE_EQ(static_cast<double>(h), 6.0);
}

TEST(HexagonEquality, EqualHexagons) {
    Hexagon<int> h1(Point<int>(0, 0), Point<int>(2, 0), Point<int>(3, 1),
                    Point<int>(2, 2), Point<int>(0, 2), Point<int>(-1, 1));
    Hexagon<int> h2(Point<int>(0, 0), Point<int>(2, 0), Point<int>(3, 1),
                    Point<int>(2, 2), Point<int>(0, 2), Point<int>(-1, 1));
    ASSERT_TRUE(h1 == h2);
}

TEST(HexagonInequality, UnequalHexagons) {
    Hexagon<int> h1(Point<int>(0, 0), Point<int>(2, 0), Point<int>(3, 1),
                    Point<int>(2, 2), Point<int>(0, 2), Point<int>(-1, 1));
    Hexagon<int> h2(Point<int>(1, 1), Point<int>(2, 3), Point<int>(3, 1),
                    Point<int>(4, 0), Point<int>(3, -1), Point<int>(1, -2));
    ASSERT_TRUE(h1 != h2);
}

TEST(OctagonGetCenter, DefaultConstructor) {
    Octagon<int> o;
    ASSERT_TRUE(o.get_center() == Point<int>(0, 0));
}

TEST(OctagonArea, ValidOctagon) {
    Octagon<int> o(Point<int>(0, 0), Point<int>(2, 0), Point<int>(3, 1),
                   Point<int>(2, 2), Point<int>(0, 2), Point<int>(-1, 1),
                   Point<int>(-2, 0), Point<int>(-1, -1));
    ASSERT_DOUBLE_EQ(static_cast<double>(o), 8.0);
}

TEST(OctagonEquality, EqualOctagons) {
    Octagon<int> o1(Point<int>(0, 0), Point<int>(1, 1), Point<int>(2, 1),
                     Point<int>(3, 0), Point<int>(2, -1), Point<int>(1, -1),
                     Point<int>(0, -1), Point<int>(-1, 0));
    Octagon<int> o2(Point<int>(0, 0), Point<int>(1, 1), Point<int>(2, 1),
                     Point<int>(3, 0), Point<int>(2, -1), Point<int>(1, -1),
                     Point<int>(0, -1), Point<int>(-1, 0));
    ASSERT_TRUE(o1 == o2);
}

TEST(OctagonInequality, UnequalOctagons) {
    Octagon<int> o1(Point<int>(0, 0), Point<int>(1, 1), Point<int>(2, 1),
                     Point<int>(3, 0), Point<int>(2, -1), Point<int>(1, -1),
                     Point<int>(0, -1), Point<int>(-1, 0));
    Octagon<int> o2(Point<int>(1, 1), Point<int>(2, 2), Point<int>(3, 1),
                     Point<int>(4, 0), Point<int>(3, -1), Point<int>(1, -2),
                     Point<int>(-1, -2), Point<int>(-2, -1));
    ASSERT_TRUE(o1 != o2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}