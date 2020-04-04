// Copyright © Mattias Larsson Sköld 2020

#include "log.h"

#include <iostream>

using namespace std;

namespace {
std::ostream *info = &cout;
std::ostream *error = &cerr;
std::ostream *verbose = &cout;
} // namespace

namespace Log {

void configureLog(std::ostream &i, std::ostream &e, std::ostream &v) {
    info = &i;
    error = &e;
    verbose = &v;
}

auto iout() -> std::ostream & {
    return *::info;
}

auto eout() -> std::ostream & {
    return *::error;
}

auto vout() -> std::ostream & {
    return *::verbose;
}

} // namespace Log
