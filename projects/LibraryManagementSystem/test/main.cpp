#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Book.cpp"

/*
 * === Gtest Important Notes ========
 * - ASSERT VS EXPECT 
 * - When you test some class  , then you MUST include the .cpp file NOT .H file
 * - 
 *
 *
 *
 *
 *
 * */

int add(int first , int second) {
    return first + second;
}
// the best structure for testing untill now

TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(AddTest, NegativeAndPositive) {
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(AddTest, Zeros) {
    EXPECT_EQ(add(0, 0), 0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

