#include <gtest/gtest.h>
#include "laba2.h"

TEST(Laba2Test, add){
    Money m1("12345");
    Money m2("678");
    Money res = m1.add(m2);
    EXPECT_EQ(res.tostr(), "13023");
}

TEST(Laba2Test, minus){
    Money m1("300");
    Money m2("100");
    Money res = m1.minus(m2);
    EXPECT_EQ(res.tostr(), "200");
}

TEST(Laba2Test, copy){
    Money m1("12345");
    Money res = m1.copy();
    EXPECT_TRUE(res.ravno(m1));
    EXPECT_NE(&res, &m1);
}

TEST(Laba2Test, sravn){
    Money m1("12345");
    Money m2("678");
    EXPECT_FALSE(m1.ravno(m2));
    EXPECT_FALSE(m1.men(m2));
    EXPECT_TRUE(m1.bol(m2));
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

