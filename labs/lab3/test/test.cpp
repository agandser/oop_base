#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"
#include "array.h"
#include <gtest/gtest.h>
#include <cmath>

// Hexagon
TEST(hex_get_center, test01) { 
    Hexagon h(Point(0, 0), Point(1, 0), Point(1.5, std::sqrt(3) / 2), Point(1, std::sqrt(3)), Point(0, std::sqrt(3)), Point(-0.5, std::sqrt(3) / 2));
    ASSERT_TRUE(h.get_center() == Point(0.5, std::sqrt(3) / 2));
}

TEST(hex_copy_constructor, test02) {
    Hexagon h1(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    Hexagon h2 = h1;
    ASSERT_TRUE(h2.get_center() == h1.get_center());
    ASSERT_DOUBLE_EQ(static_cast<double>(h2), static_cast<double>(h1));  // Проверка равенства площадей
}

TEST(hex_copy_assignment, test03) {
    Hexagon h1(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    Hexagon h2;
    h2 = h1;
    ASSERT_TRUE(h2.get_center() == h1.get_center());
    ASSERT_DOUBLE_EQ(static_cast<double>(h2), static_cast<double>(h1));
}

TEST(hex_move_constructor, test04) {
    Hexagon h1(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    Hexagon h2 = std::move(h1);
    ASSERT_TRUE(h2.get_center() == Point(1, 0.5));
}

TEST(hex_move_assignment, test05) {
    Hexagon h1(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    Hexagon h2;
    h2 = std::move(h1);
    ASSERT_TRUE(h2.get_center() == Point(1, 0.5));
}

TEST(hex_comparison_operators, test06) {
    Hexagon h1(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    Hexagon h2(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    ASSERT_TRUE(h1 == h2);
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_area, test07) {
    Hexagon h(Point(0, 0), Point(1, 0), Point(1.5, std::sqrt(3) / 2), Point(1, std::sqrt(3)), Point(0, std::sqrt(3)), Point(-0.5, std::sqrt(3) / 2));
    double expected_area = (3 * std::sqrt(3)) / 2;
    ASSERT_DOUBLE_EQ(static_cast<double>(h), expected_area);
}


//triangle
TEST(triangle_get_center, test01) {
    Triangle t(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    ASSERT_TRUE(t.get_center() == Point(0.5, std::sqrt(3) / 6));
}

TEST(triangle_copy_constructor, test02) {
    Triangle t1(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    Triangle t2 = t1;
    ASSERT_TRUE(t2.get_center() == t1.get_center());
    ASSERT_DOUBLE_EQ(static_cast<double>(t2), static_cast<double>(t1));
}

TEST(triangle_copy_assignment, test03) {
    Triangle t1(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    Triangle t2;
    t2 = t1;
    ASSERT_TRUE(t2.get_center() == t1.get_center());
    ASSERT_DOUBLE_EQ(static_cast<double>(t2), static_cast<double>(t1));
}

TEST(triangle_move_constructor, test04) {
    Triangle t1(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    Triangle t2 = std::move(t1);
    ASSERT_TRUE(t2.get_center() == Point(0.5, std::sqrt(3) / 6));
}

TEST(triangle_move_assignment, test05) {
    Triangle t1(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    Triangle t2;
    t2 = std::move(t1);
    ASSERT_TRUE(t2.get_center() == Point(0.5, std::sqrt(3) / 6));
}

TEST(triangle_area, test06) {
    Triangle t(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    double expected_area = (std::sqrt(3) / 4);
    ASSERT_DOUBLE_EQ(static_cast<double>(t), expected_area);
}


//Octagon
TEST(octagon_get_center, test01) {
    Octagon o(Point(1, 0), Point(2, 0), Point(3, 1), Point(3, 2), Point(2, 3), Point(1, 3), Point(0, 2), Point(0, 1));
    ASSERT_TRUE(o.get_center() == Point(1.5, 1.5));
}

TEST(octagon_copy_constructor, test02) {
    Octagon o1(Point(1, 0), Point(2, 0), Point(3, 1), Point(3, 2), Point(2, 3), Point(1, 3), Point(0, 2), Point(0, 1));
    Octagon o2 = o1;
    ASSERT_TRUE(o2.get_center() == o1.get_center());
    ASSERT_DOUBLE_EQ(static_cast<double>(o2), static_cast<double>(o1));
}

TEST(octagon_copy_assignment, test03) {
    Octagon o1(Point(1, 0), Point(2, 0), Point(3, 1), Point(3, 2), Point(2, 3), Point(1, 3), Point(0, 2), Point(0, 1));
    Octagon o2;
    o2 = o1;
    ASSERT_TRUE(o2.get_center() == o1.get_center());
    ASSERT_DOUBLE_EQ(static_cast<double>(o2), static_cast<double>(o1));
}

TEST(octagon_move_constructor, test04) {
    Octagon o1(Point(1, 0), Point(2, 0), Point(3, 1), Point(3, 2), Point(2, 3), Point(1, 3), Point(0, 2), Point(0, 1));
    Octagon o2 = std::move(o1);
    ASSERT_TRUE(o2.get_center() == Point(1.5, 1.5));
}

TEST(octagon_move_assignment, test05) {
    Octagon o1(Point(1, 0), Point(2, 0), Point(3, 1), Point(3, 2), Point(2, 3), Point(1, 3), Point(0, 2), Point(0, 1));
    Octagon o2;
    o2 = std::move(o1);
    ASSERT_TRUE(o2.get_center() == Point(1.5, 1.5));
}


//Array
TEST(array_total_area, test01) {
    Hexagon h(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    Triangle t(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    Array arr{&h, &t};
    ASSERT_DOUBLE_EQ(arr.get_total_area(), static_cast<double>(h) + static_cast<double>(t));  // Проверка суммы площадей
}

TEST(array_remove, test02) {
    Hexagon h(Point(1, 0), Point(2, 0), Point(2, 1), Point(1, 1), Point(0, 1), Point(0, 0));
    Triangle t(Point(0, 0), Point(1, 0), Point(0.5, std::sqrt(3) / 2));
    Array arr{&h, &t};
    arr.remove(0);
    ASSERT_DOUBLE_EQ(arr.get_total_area(), static_cast<double>(t));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}