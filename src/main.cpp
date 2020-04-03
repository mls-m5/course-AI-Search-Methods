// Copyright Mattias Larsson Sköld 2020

#include "city.h"
#include "loadcities.h"

#include <fstream>
#include <iostream>

using namespace std;

auto main(int /*argc*/, char * * /*argv*/) -> int {
    ifstream file("data/data.txt");

    if (!file.is_open()) {
        throw runtime_error("file could not be opened");
    }

    auto cities = loadCities(file);

    cout << cities;
}
