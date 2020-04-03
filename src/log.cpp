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

ostream &Log::i() {
    return *::info;
}

ostream &Log::e() {
    return *::error;
}

ostream &Log::v() {
    return *::verbose;
}

} // namespace Log
