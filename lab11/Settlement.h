//
// Created by Kovacs Dani on 23.11.2025.
//

#ifndef LAB11_SETTLEMENT_H
#define LAB11_SETTLEMENT_H
#include <string>
using namespace std;
#include <vector>

class Settlement {
    string name = "";
    string county= "";
    int population = 0;

public:
    Settlement(const string& name, const string& county, const int& population);
    string getName() const;
    string getCounty() const;
    int getPopulation() const;
    friend ostream& operator<<(ostream& os, const Settlement& s);
};

struct SettlementStatistics {
    virtual ~SettlementStatistics() = default;

    virtual int numSettlements() const;
    virtual int numCounties() const= 0;
    virtual int numSettlementsByCounty(const string& county) const= 0;
    virtual vector<Settlement> findSettlementsByCounty(const string& county) const= 0;
    virtual Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const= 0;
    virtual Settlement maxPopulationBySettlement() const= 0;
    virtual Settlement minPopulationBySettlement() const= 0;
    virtual vector<Settlement> findSettlementsByName(const string& name) = 0;

};

#endif //LAB11_SETTLEMENT_H