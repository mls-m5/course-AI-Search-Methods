// Copyright © Mattias Larsson Sköld 2020

#include <functional>
#include <iosfwd>

namespace Log {

struct Log {
    static std::ostream &i();
    static std::ostream &e();
    static std::ostream &v();
};

extern Log log;

void configureLog(std::ostream &info,
                  std::ostream &error,
                  std::ostream &verbose);

} // namespace Log

using Log::log;
