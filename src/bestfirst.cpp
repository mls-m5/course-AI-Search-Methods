// Copyright © Mattias Larsson Sköld 2020

#include "bestfirst.h"

#include "informedsearch.h"

auto bestFirst(const City *start, const City *finish) -> RawCityList {
    return informedSearch(start, finish, [](auto &a, auto &b) -> bool {
        return a.back()->heuristic < b.back()->heuristic;
    });
}
