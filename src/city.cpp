// Copyright © Mattias Larsson Sköld 2020

#include "city.h"

#include <iostream>

using namespace std;

ostream &operator<<(ostream &stream, const City &city) {
    cout << city.name << " " << city.x << "," << city.y << "\n";
    cout << "\t";
    for (auto c : city.connections) {
        cout << c->name << " ";
    }
    cout << "\n";
    return stream;
}

ostream &operator<<(ostream &stream, const CityList &cities) {
    for (auto &city : cities) {
        stream << *city;
    }
    return stream;
}
