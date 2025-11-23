//
// Created by Kovacs Dani on 23.11.2025.
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMPL_H
#define LAB11_SETTLEMENTSTATISTICSIMPL_H

#include "Settlement.h"
#include <vector>
#include <map>
#include <string>

class SettlementStatisticsImpl : public SettlementStatistics {
private:
    multimap<string, Settlement> settlements;

public:
    explicit SettlementStatisticsImpl(const string& filename);
    int numSettlements() const override;
    int numCounties() const override;
    int numSettlementsByCounty(const string &county) const override;
    vector<Settlement> findSettlementsByCounty(const string &county) const override;
    vector<Settlement> findSettlementsByName(const string &name) override;
    Settlement findSettlementsByNameAndCounty(const string &name, const string &county) const override;
    Settlement maxPopulationBySettlement() const override;
    Settlement minPopulationBySettlement() const override;

};


#endif //LAB11_SETTLEMENTSTATISTICSIMPL_H