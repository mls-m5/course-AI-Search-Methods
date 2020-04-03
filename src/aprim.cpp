// Copyright © Mattias Larsson Sköld 2020

#include "aprim.h"
#include "informedsearch.h"

auto aprim(const City *start, const City *finish) -> RawCityList {
    return informedSearch(start, finish, [](RawCityList &a, RawCityList &b) {
        // Maybe not optimal performance but that's a problem for someday when
        // this solution will need to be more performant
        return length(a) + a.back()->heuristic <
               length(b) + b.back()->heuristic;
    });
}
