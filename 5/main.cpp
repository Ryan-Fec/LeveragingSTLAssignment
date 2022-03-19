#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

int main() {
    auto cars = randomCars();
    std::cout << "Cars: " << cars << "\n";

    std::vector<Tag<Car>> taggedCars;
    for (auto car : cars) {
        if (car.price() < 10000.00 || (std::strcmp(car.vin().substr(0, 1).c_str(), "A")) >= 0 && std::strcmp(car.vin().substr(0, 1).c_str(), "F") <= 0) {
            Tag tag{ true, car };
            taggedCars.push_back(tag);
        }
        else {
            Tag tag{ false, car }; 
            taggedCars.push_back(tag);
        }
    }
    if (char("B") <= char("F")) {
        std::cout << "True";
    }
    std::partition(taggedCars.begin(), taggedCars.end(), [](Tag<Car> tag) {
        return tag.isTagged();
        });



    std::cout << "Tagged Cars: " << taggedCars << "\n";
}
