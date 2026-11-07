#include <gtest/gtest.h>
#include "enums/coin.hpp"

TEST(CoinTest, ValueOfPenny) {
    EXPECT_EQ(valueOf(Coin::PENNY), 1);
}

TEST(CoinTest, ValueOfNickel) {
    EXPECT_EQ(valueOf(Coin::NICKEL), 5);
}

TEST(CoinTest, ValueOfDime) {
    EXPECT_EQ(valueOf(Coin::DIME), 10);
}

TEST(CoinTest, ValueOfQuarter) {
    EXPECT_EQ(valueOf(Coin::QUARTER), 25);
}

TEST(CoinTest, ValuesCanBeSummed) {
    EXPECT_EQ(valueOf(Coin::QUARTER) + valueOf(Coin::DIME) + valueOf(Coin::NICKEL) + valueOf(Coin::PENNY), 41);
}

TEST(CoinTest, ValueOfIsConstexpr) {
    static_assert(valueOf(Coin::PENNY) == 1);
    static_assert(valueOf(Coin::QUARTER) == 25);
    SUCCEED();
}
