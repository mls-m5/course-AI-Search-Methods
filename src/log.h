// Copyright © Mattias Larsson Sköld 2020

#include <iosfwd>

namespace Log {

//! Information out:
//! Should usually be printed
std::ostream &iout();

//! Error out:
//! Printed to cerr or similar
std::ostream &eout();

//! Verbose out
//! Printied if verbosity is enabled
std::ostream &vout();

void configureLog(std::ostream &info,
                  std::ostream &error,
                  std::ostream &verbose);

} // namespace Log
