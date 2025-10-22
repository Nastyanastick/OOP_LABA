#include <gtest/gtest.h>
#include "laba1.h"


TEST(Laba1Test, NormalCases) {
    EXPECT_EQ(choco(2, 1), 1);
    EXPECT_EQ(choco(3, 1), 2);
    EXPECT_EQ(choco(2, 2), 3);
}

TEST(Laba1Test, ZeroCases) {
    EXPECT_EQ(choco(0, 5), 0);
    EXPECT_EQ(choco(3, 0), 0);
    EXPECT_EQ(choco(0, 0), 0);
}

TEST(Laba1Test, NegativeCases) {
    EXPECT_EQ(choco(-1, 5), 0);
    EXPECT_EQ(choco(3, -2), 0);
    EXPECT_EQ(choco(-1, -1), 0);
}

TEST(Laba1Test, SingleSquare) {
    EXPECT_EQ(choco(1, 1), 0);
}