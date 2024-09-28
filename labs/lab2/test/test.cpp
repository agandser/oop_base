#include <gtest/gtest.h>
#include "../include/Hex.h"

// Тестирование конструкторов
TEST(Constructors, default_constructor) {
    Hex a;
    ASSERT_TRUE(a.getsize() == 0);
}

TEST(Constructors, string_constructor) {
    Hex a("1A3F");
    ASSERT_TRUE(a.getvalue() == "1A3F");
}

TEST(Constructors, string_constructor_2) {
    Hex a("01A3F");
    ASSERT_TRUE(a.getvalue() == "1A3F");
}

TEST(Constructors, initializer_list_constructor) {
    Hex a{'A', 'B', 'C'};
    ASSERT_TRUE(a.getvalue() == "ABC");
}

TEST(Constructors, copy_constructor) {
    Hex a("1A3F");
    Hex b("123");
    b.copy(a);
    ASSERT_TRUE(b.getvalue() == "1A3F");
}

TEST(Constructors, move_constructor) {
    Hex a("1A3F");
    Hex b = std::move(a);
    ASSERT_TRUE(b.getvalue() == "1A3F");
    ASSERT_TRUE(a.getsize() == 0); // Перемещенный объект должен быть пустым
}

// Тестирование арифметических методов
TEST(Arithmetic, addition) {
    Hex a("1A3F");
    Hex b("1C4D");
    Hex result = a.add(b);
    ASSERT_TRUE(result.getvalue() == "368C"); // Проверяем сумму
}

TEST(Arithmetic, subtraction) {
    Hex a("1C4D");
    Hex b("1A3F");
    Hex result = a.subtract(b);
    ASSERT_TRUE(result.getvalue() == "20E"); // Проверяем разность
}

TEST(Arithmetic, addition_with_carry) {
    Hex a("FFF");
    Hex b("1");
    Hex result = a.add(b);
    ASSERT_TRUE(result.getvalue() == "1000"); // Проверяем перенос
}


// Тестирование логических методов
TEST(Comparison, equals) {
    Hex a("1A3F");
    Hex b("1A3F");
    ASSERT_TRUE(a.is_equal(b));
}

TEST(Comparison, not_equals) {
    Hex a("1A3F");
    Hex b("1C4D");
    ASSERT_TRUE(a.is_not_equal(b));
}

TEST(Comparison, less_than) {
    Hex a("1A3F");
    Hex b("1C4D");
    ASSERT_TRUE(a.is_less(b));
}

TEST(Comparison, greater_than) {
    Hex a("1C4D");
    Hex b("1A3F");
    ASSERT_TRUE(a.is_greater(b));
}

TEST(Comparison, less_or_equal) {
    Hex a("1A3F");
    Hex b("1A3F");
    ASSERT_TRUE(a.is_less_or_equal(b));
}

TEST(Comparison, greater_or_equal) {
    Hex a("1A3F");
    Hex b("1A3F");
    ASSERT_TRUE(a.is_greater_or_equal(b));
}

// Тестирование методов доступа
TEST(Accessors, get_value) {
    Hex a("1A3F");
    ASSERT_TRUE(a.getvalue() == "1A3F");
}

TEST(Accessors, get_size) {
    Hex a("1A3F");
    ASSERT_TRUE(a.getsize() == 4);
}

// Тестирование работы с пустыми объектами
TEST(Empty, addition_with_empty) {
    Hex a;
    Hex b("1A3F");
    Hex result = a.add(b);
    ASSERT_TRUE(result.getvalue() == "1A3F"); // Проверяем сложение с пустым объектом
}

TEST(Empty, subtraction_with_empty) {
    Hex a;
    Hex b("1A3F");
    ASSERT_ANY_THROW(a.subtract(b)); // Проверяем вычитание из пустого объекта
}

TEST(Empty, equals_with_empty) {
    Hex a;
    Hex b;
    ASSERT_TRUE(a.is_equal(b)); // Пустые объекты должны быть равны
}

TEST(Empty, not_equals_with_empty) {
    Hex a("1A3F");
    Hex b;
    ASSERT_TRUE(a.is_not_equal(b)); // Пустой и непустой объект не равны
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}