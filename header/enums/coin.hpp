#pragma once

enum class Coin {
    PENNY = 1,
    NICKEL = 5,
    DIME = 10,
    QUARTER = 25,
};

constexpr int valueOf(Coin coin) {
    return static_cast<int>(coin);
}