// Copyright © Mattias Larsson Sköld 2020

#pragma once

#include "city.h"
#include <functional>

//! @param comparison        how to sort the results
auto informedSearch(
    const City *start,
    const City *finish,
    std::function<bool(RawCityList &, RawCityList &)> comparison)
    -> RawCityList;
