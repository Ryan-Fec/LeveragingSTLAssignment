#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto integers = randomIntegers();
    std::cout << "Initial: " << integers << "\n";

    std::sort(std::begin(integers), integers.begin() + integers.size() / 2);
    std::sort(integers.begin() + integers.size() / 2, std::end(integers));
    std::reverse(integers.begin() + integers.size() / 2, std::end(integers));
    std::cout << "Bitonic: " << integers << "\n";
}
