#include <gtest/gtest.h>
#include "../include/isafraid.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(isafraid("Пятница",1)==0);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(isafraid("Воскресенье",0)==0);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(isafraid("Суббота",56)==1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}