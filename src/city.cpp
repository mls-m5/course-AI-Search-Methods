// Copyright © Mattias Larsson Sköld 2020

#include "city.h"

#include <iostream>
#include <numeric>

using namespace std;

ostream &operator<<(ostream &stream, const City &city) {
    stream << city.name << " " << city.x << "," << city.y
           << " heuristic=" << city.heuristic << "\n";
    stream << "\t";
    for (auto c : city.connections) {
        stream << c->name << " ";
    }
    stream << "\n";
    return stream;
}

ostream &operator<<(ostream &stream, const CityList &cities) {
    for (auto &city : cities) {
        stream << *city;
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const RawCityList &cities) {
    stream << "Route:" << endl;
    stream << cities.front()->name << endl;
    double total = 0;

    for (size_t i = 1; i < cities.size(); ++i) {
        auto &a = cities[i - 1];
        auto &b = cities[i];

        auto dx = b->x - a->x;
        auto dy = b->y - a->y;

        auto len = dx * dx + dy * dy;
        total += len;

        stream << "distance: " << len << " --> total: " << total << endl;

        stream << b->name << endl;
    }
    return stream;
}

auto expand(const RawCityList &origin, const City *city) -> RawCityList {
    RawCityList ret = origin;
    ret.push_back(city);
    return ret;
}

double length(const RawCityList &route) {
    double length = 0;
    for (size_t i = 1; i < route.size(); ++i) {
        auto &a = route[i - 1];
        auto &b = route[i];
        auto dx = a->x - b->x;
        auto dy = a->y - b->y;
        length += (dx * dx + dy * dy);
    }
    return length;
}
