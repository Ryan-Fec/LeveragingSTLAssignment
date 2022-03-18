#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Initial: " << cars << "\n";

    std::cout << "Reversed: ";
    for (auto it = cars.rbegin(); it != cars.rend(); it++) {
        std::cout << *it << "\n";
    }
    std::cout << "\n";
