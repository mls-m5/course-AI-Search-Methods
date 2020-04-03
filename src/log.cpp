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

ostream &iout() {
    return *::info;
}

ostream &eout() {
    return *::error;
}

ostream &vout() {
    return *::verbose;
}

} // namespace Log
