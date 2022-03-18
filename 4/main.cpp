#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

bool anyPrime(const std::vector<int>& values);

int main() {
    auto integers = randomIntegers();
    std::cout << "Integers: " << integers << "\n";
    std::cout << "Are there any primes? " << (anyPrime(integers) ? "yes" : "no") << "\n";
}

bool anyPrime(const std::vector<int>& values) {
    
    for (auto element : values) {
        for (auto i = 2; i <= element / 2; i++) {
            auto is_prime = true;
            if (element % i == 0 || element == 0 || element == 1) {
                is_prime = false;
                break;
            }
            if (is_prime == true) {
                return true;
            }
        } 
    }
    
    return false;
}
