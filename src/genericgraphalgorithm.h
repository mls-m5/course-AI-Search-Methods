// Copyright © Mattias Larsson Sköld 2020

#include "city.h"

//! Implement a _general_ graph search algorith
//! @param breadthFirst     If true use breadth first, else use depth first
auto genericGraphAlgorithm(const City *start,
                           const City *finish,
                           bool breadthFirst = true) -> RawCityList;
