// Copyright © Mattias Larsson Sköld 2020

#include "city.h"

//! Performs a breadth first _or_ depth first search
//! @param breadthFirst     If true use breadth first, else use depth first
auto uninformedSearch(const City *start,
                      const City *finish,
                      bool breadthFirst = true) -> RawCityList;
