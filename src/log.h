// Copyright © Mattias Larsson Sköld 2020

#include <functional>
#include <iosfwd>

namespace Log {

std::ostream &iout();
std::ostream &eout();
std::ostream &vout();

void configureLog(std::ostream &info,
                  std::ostream &error,
                  std::ostream &verbose);

} // namespace Log
