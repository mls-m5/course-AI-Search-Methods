// Copyright © Mattias Larsson Sköld 2020

#include "loadcities.h"
#include "log.h"

#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

auto findCity(const CityList &cities, std::string_view name) -> City * {
    for (auto &city : cities) {
        if (city->name == name) {
            return city.get();
        }
    }
    throw runtime_error("could not find city "s + string(name));
}

void loadConnections(istream &stream, CityList &cities) {
    string line;
    while (getline(stream, line)) {
        if (line.empty()) {
            continue;
        }

        istringstream ss(line);
        string cityName;
        vector<City *> route;
        while (ss >> cityName) {
            route.push_back(findCity(cities, cityName));
        }

        for (size_t i = 1; i < route.size(); ++i) {
            route.at(i)->connections.push_back(route.at(i - 1));
            route.at(i - 1)->connections.push_back(route.at(i));
        }
    }
}

void calculateHeuristic(CityList &cities) {
    auto bucharest = findCity(cities, "Bucharest");
    for (auto &city : cities) {
        auto dx = city->x - bucharest->x;
        auto dy = city->y - bucharest->y;
        auto len = sqrt(dx * dx + dy * dy);
        city->heuristic = len;
    }
}

auto loadCities(istream &stream) -> CityList {
    string line;

    getline(stream, line); // Throw away first line

    CityList cities;
    while (getline(stream, line)) {
        if (line.empty()) {
            continue;
        }
        else if (line == "Routes:") {
            break;
        }

        City city;
        istringstream ss(line);
        ss >> city.name >> city.x >> city.y;

        cities.push_back(make_unique<City>(city));
    }

    loadConnections(stream, cities);
    calculateHeuristic(cities);

    return cities;
}
