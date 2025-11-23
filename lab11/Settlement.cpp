//
// Created by Kovacs Dani on 23.11.2025.
//

#include "Settlement.h"

#include <ostream>

Settlement::Settlement(const string &name, const string &county, const int &population): name(name), county(county), population(population) {}

string Settlement::getName() const {
    return name;
}

string Settlement::getCounty() const {
    return county;
}

int Settlement::getPopulation() const {
    return population;
}

ostream& operator<<(ostream& os, const Settlement &s) {
   os << "Name: " << s.getName() << "\n" << "County: " << s.getCounty() << "\n" << "Population: " << s.getPopulation() << "\n-----------------";
   return os;
}
