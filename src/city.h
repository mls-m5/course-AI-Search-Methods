// Copyright © Mattias Larsson Sköld 2020

#pragma once

#include <iosfwd>
#include <memory>
#include <string>
#include <vector>

struct City {
    std::string name;
    std::vector<City *> connections;
    double x;
    double y;
};

typedef std::vector<std::unique_ptr<City>> CityList;
typedef std::vector<const City *> RawCityList;

std::ostream &operator<<(std::ostream &stream, const City &city);
std::ostream &operator<<(std::ostream &stream, const CityList &cities);

//! Print route statistics
std::ostream &operator<<(std::ostream &stream, const RawCityList &cities);

auto expand(const RawCityList &origin, const City *city) -> RawCityList;
