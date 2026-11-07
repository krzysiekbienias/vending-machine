#include <gtest/gtest.h>
#include "entities/item.hpp"

TEST(ItemTest, ConstructorStoresCode) {
    Item item("A1", "Cola", 150);
    EXPECT_EQ(item.getCode(), "A1");
}

TEST(ItemTest, ConstructorStoresName) {
    Item item("A1", "Cola", 150);
    EXPECT_EQ(item.getName(), "Cola");
}

TEST(ItemTest, ConstructorStoresPrice) {
    Item item("A1", "Cola", 150);
    EXPECT_EQ(item.getPrice(), 150);
}

TEST(ItemTest, ZeroPrice) {
    Item item("B2", "Free sample", 0);
    EXPECT_EQ(item.getPrice(), 0);
}

TEST(ItemTest, NameWithSpaces) {
    Item item("C3", "Orange Juice", 200);
    EXPECT_EQ(item.getName(), "Orange Juice");
}

TEST(ItemTest, EmptyName) {
    Item item("D4", "", 100);
    EXPECT_EQ(item.getName(), "");
}

TEST(ItemTest, CopyKeepsAllFields) {
    Item original("A1", "Cola", 150);
    Item copy = original;
    EXPECT_EQ(copy.getCode(), "A1");
    EXPECT_EQ(copy.getName(), "Cola");
    EXPECT_EQ(copy.getPrice(), 150);
}
