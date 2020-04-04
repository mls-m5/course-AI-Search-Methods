// Copyright © Mattias Larsson Sköld 2020

#include "uninformedsearch.h"

#include "log.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace Log;

auto uninformedSearch(const City *start, const City *finish, bool breadthFirst)
    -> RawCityList {
    using namespace std;
    vector<const City *> closed;
    list<RawCityList> fringe{{start}};

    while (true) {
        if (fringe.empty()) {
            return {};
        }

        RawCityList current;
        if (breadthFirst) {
            current = move(fringe.front());
            fringe.erase(fringe.begin());
        }
        else {
            current = move(fringe.back());
            fringe.pop_back();
        }

        vout() << "one line -- fringe size: " << fringe.size() << ", ";
        vout() << " route length " << current.size() << "\n";
        vout() << "\t" << current.back()->name << "\n";

        if (current.back() == finish) {
            return RawCityList(current);
        }
        else if (std::find(closed.begin(), closed.end(), current.back()) ==
                 closed.end()) {
            closed.push_back(current.back());
            for (auto &connection : current.back()->connections) {
                fringe.push_back(expand(current, connection));
            }
        }
    }
}
