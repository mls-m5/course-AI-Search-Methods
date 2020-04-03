// Copyright © Mattias Larsson Sköld 2020

#pragma once

#include "city.h"

//! Also called the "greedy algorithm"
auto bestFirst(const City *start, const City *finish) -> RawCityList;
