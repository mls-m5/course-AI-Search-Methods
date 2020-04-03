// Copyright Mattias Larsson Sköld 2020

#include "city.h"
#include "loadcities.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

//! Implement a _general_ graph search algorith
auto graphSearchAlgorithm(const City *start, const City *finish)
    -> RawCityList {
    vector<const City *> closed;
    queue<RawCityList> fringe;
    fringe.emplace(RawCityList{start});

    while (true) {
        if (fringe.empty()) {
            return {};
        }
        auto current = move(fringe.front());
        fringe.pop();
        cout << "one line -- fringe size: " << fringe.size() << endl;
        cout << "\t" << current.back()->name << endl;
        if (current.back() == finish) {
            return RawCityList(current);
        }
        else if (std::find(closed.begin(), closed.end(), current.back()) ==
                 closed.end()) {
            //            closed.insert(current.back());
            closed.push_back(current.back());
            for (auto &connection : current.back()->connections) {
                fringe.push(expand(current, connection));
            }
        }
    }
}

auto main(int /*argc*/, char * * /*argv*/) -> int {
    ifstream file("data/data.txt");

    if (!file.is_open()) {
        throw runtime_error("file could not be opened");
    }

    auto cities = loadCities(file);

    cout << cities;

    auto route = graphSearchAlgorithm(findCity(cities, "Arad"),
                                      findCity(cities, "Bucharest"));

    cout << "Route: " << endl;
    for (auto city : route) {
        cout << city->name << " " << endl;
    }
    cout << endl;
}
