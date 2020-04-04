// Copyright © Mattias Larsson Sköld 2020

#include <iosfwd>

namespace Log {

//! Information out:
//! Should usually be printed
auto iout() -> std::ostream &;

//! Error out:
//! Printed to cerr or similar
auto eout() -> std::ostream &;

//! Verbose out
//! Printied if verbosity is enabled
auto vout() -> std::ostream &;

void configureLog(std::ostream &info,
                  std::ostream &error,
                  std::ostream &verbose);

} // namespace Log
