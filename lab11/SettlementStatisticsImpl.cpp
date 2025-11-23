//
// Created by Kovacs Dani on 23.11.2025.
//

#include "SettlementStatisticsImpl.h"
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <stdexcept>

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string> uniqueCounties;

    for (auto& s : settlements) {
        uniqueCounties.insert(s.first);
    }

    return uniqueCounties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return settlements.count(county);
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;

    auto range = settlements.equal_range(county);
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(it->second);
    }
    return result;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> result;
    for (auto &p :settlements) {
        if (p.second.getName() == name) {
            result.push_back(p.second);
        }
    }
    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    auto range = settlements.equal_range(county);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getName() == name) {
            return it->second;
        }
    }
    throw runtime_error("Settlement not found");
}

Settlement SettlementStatisticsImpl::maxPopulationBySettlement() const {
    if (settlements.empty()) throw runtime_error("Dataset empty");

    auto maxIt = settlements.begin();
    for (auto it = settlements.begin(); it != settlements.end(); ++it) {
        if (it->second.getPopulation() > maxIt->second.getPopulation()) {
            maxIt = it;
        }
    }
    return maxIt->second;
}

Settlement SettlementStatisticsImpl::minPopulationBySettlement() const {
    if (settlements.empty()) throw runtime_error("Dataset empty");

    auto minIt = settlements.begin();
    for (auto it = settlements.begin(); it != settlements.end(); ++it) {
        if (it->second.getPopulation() < minIt->second.getPopulation()) {
            minIt = it;
        }
    }
    return minIt->second;
}

SettlementStatisticsImpl::SettlementStatisticsImpl(const string &filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        throw runtime_error("Nem lehet megnyitni a fajlt.");
    }

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string name, county, popStr;

        getline(ss, name, ',');
        getline(ss, county, ',');
        getline(ss, popStr, ',');

        int population = stoi(popStr);

        settlements.insert({county, Settlement(name, county, population)});
    }
}
