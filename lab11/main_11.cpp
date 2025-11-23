#include <iostream>

#include "SettlementStatisticsImpl.h"

int main() {

    SettlementStatisticsImpl stats("telepulesek.csv");

    cout << "Total settlements: " << stats.numSettlements() << endl;
    cout << "Total counties: " << stats.numCounties() << endl;
    cout << "\n--- MS settlements ---\n";
    for (auto& s : stats.findSettlementsByCounty("MS"))
        cout << s << endl;

    cout << "\n--- Settlement Panet in MS ---\n";
    cout << stats.findSettlementsByNameAndCounty("Panet", "MS") << endl;

    cout << "\n--- Max population settlement ---\n";
    cout << stats.maxPopulationBySettlement() << endl;

    cout << "\n--- Min population settlement ---\n";
    cout << stats.minPopulationBySettlement() << endl;
    return 0;
}
