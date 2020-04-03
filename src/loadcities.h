// Copyright © Mattias Larsson Sköld 2020

#pragma once

#include "city.h"

auto findCity(const CityList &cities, std::string_view name) -> City *;

auto loadCities(std::istream &stream) -> CityList;
