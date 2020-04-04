// Copyright Mattias Larsson Sköld 2020

#include "aprim.h"
#include "bestfirst.h"
#include "city.h"
#include "loadcities.h"
#include "log.h"
#include "uninformedsearch.h"

#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;
using namespace Log;

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

    vout() << cities;

    auto start = findCity(cities, "Arad");
    auto finish = findCity(cities, "Bucharest");

    {
        iout() << "---- Breadth first -------" << endl;
        auto route = uninformedSearch(start, finish);
        iout() << route;
    }

    {
        iout() << "---- Depth first -------" << endl;
        auto route = uninformedSearch(start, finish, false);
        iout() << route;
    }

    {
        iout() << "---- best first -------" << endl;
        auto route = bestFirst(start, finish);
        iout() << route;
    }

    {
        iout() << "---- aprim search -------" << endl;
        auto route = aprim(start, finish);
        iout() << route;
    }
}
