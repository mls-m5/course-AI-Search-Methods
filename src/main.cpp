// Copyright Mattias Larsson Sköld 2020

#include "city.h"
#include "genericgraphalgorithm.h"
#include "loadcities.h"
#include "log.h"

#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

namespace {

ofstream nullStream; // Unopened ignores output
ofstream fileLog("log.txt");

} // namespace

auto parseArguments(vector<string_view> args) {
    for (auto arg : args) {
        if (arg == "-v" || arg == "--verbose") {
            Log::configureLog(cout, cerr, cout);
        }
        else if (arg == "-h" || arg == "--help") {
            cout
                << "-h --help            Print this text\n"
                   "-v --verbose         Print to screen instead of log file\n";
            exit(0);
        }
    }
}

auto main(int argc, char **argv) -> int {
    cout.tie(&fileLog);
    Log::configureLog(cout, cerr, fileLog);
    parseArguments(vector<string_view>(argv + 1, argv + argc));

    ifstream file("data/data.txt");

    if (!file.is_open()) {
        throw runtime_error("file could not be opened");
    }

    auto cities = loadCities(file);

    log.v() << cities;

    auto start = findCity(cities, "Arad");
    auto finish = findCity(cities, "Bucharest");

    {
        log.i() << "---- Breadth first -------" << endl;
        auto route = genericGraphAlgorithm(start, finish);
        log.i() << route;
    }

    {
        log.i() << "---- Depth first -------" << endl;
        auto route = genericGraphAlgorithm(start, finish);
        log.i() << route;
    }
}
