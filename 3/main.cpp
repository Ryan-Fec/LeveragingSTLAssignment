#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include "Utility.h"
#include "Car.h"

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";
    
    std::vector<double> prices;

    for (auto i = 0; i != cars.size(); i++) {
        prices.push_back(cars.at(i).price());
    }
    double sum = std::accumulate(prices.begin(), prices.end(), 0.0);

    double average = static_cast<double>(sum) / static_cast<double>(prices.size());

    std::vector<double> range;

    if (std::max_element(prices.cbegin(), prices.cend()) != prices.end()) {
        range.push_back(*std::max_element(prices.cbegin(), prices.cend()));
    }

    if (std::min_element(prices.cbegin(), prices.cend()) != prices.end()) {
        range.push_back(*std::min_element(prices.cbegin(), prices.cend()));
    }

    std::cout << "The average price is: $" << average << "\n";

    std::cout << "The range is: $" << range << "\n";
}
