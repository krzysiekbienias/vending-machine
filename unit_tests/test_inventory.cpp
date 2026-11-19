#include "inventory.hpp"
#include <gtest/gtest.h>

TEST(InventoryTest, GetItemReturnsAddedItem) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 5);
    EXPECT_EQ(inventory.get_item("A1"), &cola);
}

TEST(InventoryTest, GetItemForUnknownCodeReturnsNullptr) {
    Inventory inventory;
    EXPECT_EQ(inventory.get_item("Z9"), nullptr);
}

TEST(InventoryTest, ItemWithPositiveQuantityIsAvailable) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 5);
    EXPECT_TRUE(inventory.is_available("A1"));
}

TEST(InventoryTest, ItemWithZeroQuantityIsNotAvailable) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 0);
    EXPECT_FALSE(inventory.is_available("A1"));
}

TEST(InventoryTest, UnknownCodeIsNotAvailable) {
    Inventory inventory;
    EXPECT_FALSE(inventory.is_available("Z9"));
}

TEST(InventoryTest, ReduceStockKeepsItemAvailableWhileUnitsLeft) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 2);
    inventory.reduce_stock("A1");
    EXPECT_TRUE(inventory.is_available("A1"));
}

TEST(InventoryTest, ReduceStockOfLastUnitMakesItemUnavailable) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 1);
    inventory.reduce_stock("A1");
    EXPECT_FALSE(inventory.is_available("A1"));
}

TEST(InventoryTest, ReduceStockForUnknownCodeThrows) {
    Inventory inventory;
    EXPECT_THROW(inventory.reduce_stock("Z9"), std::exception);
}

TEST(InventoryTest, ReduceStockForZeroQuantityThrows) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 0);
    EXPECT_THROW(inventory.reduce_stock("A1"), std::exception);
}

TEST(InventoryTest, ReduceStockAfterLastUnitThrows) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 1);
    inventory.reduce_stock("A1");
    EXPECT_THROW(inventory.reduce_stock("A1"), std::exception);
}

TEST(InventoryTest, AddItemUnderExistingCodeReplacesItem) {
    Item cola("A1", "Cola", 150);
    Item pepsi("A1", "Pepsi", 140);
    Inventory inventory;
    inventory.add_item("A1", &cola, 5);
    inventory.add_item("A1", &pepsi, 3);
    EXPECT_EQ(inventory.get_item("A1"), &pepsi);
}

TEST(InventoryTest, AddItemUnderExistingCodeResetsQuantity) {
    Item cola("A1", "Cola", 150);
    Inventory inventory;
    inventory.add_item("A1", &cola, 5);
    inventory.add_item("A1", &cola, 0);
    EXPECT_FALSE(inventory.is_available("A1"));
}

TEST(InventoryTest, ItemsUnderDifferentCodesAreIndependent) {
    Item cola("A1", "Cola", 150);
    Item chips("B2", "Chips", 100);
    Inventory inventory;
    inventory.add_item("A1", &cola, 1);
    inventory.add_item("B2", &chips, 1);
    inventory.reduce_stock("A1");
    EXPECT_FALSE(inventory.is_available("A1"));
    EXPECT_TRUE(inventory.is_available("B2"));
    EXPECT_EQ(inventory.get_item("B2"), &chips);
}
