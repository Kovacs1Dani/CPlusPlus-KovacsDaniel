//
// Created by Kovacs Dani on 29.09.2025.
//

#ifndef LAB3_POINTSET_H
#define LAB3_POINTSET_H
#include <vector>

#include "point.h"

class PointSet {
    std::vector<Point> points;
    int n;
    std::vector<double> distances;
    void computeDistances();

    public:
        PointSet (int n = 100);
        double maxDistance() const;
        double minDistance() const;
        int numDistances() const;
        void printPoints() const;
        void printDistances() const;
        void sortPointsX();
        void sortPointsY();
        void sortDistances();
        int numDistinctDistances();
};




#endif //LAB3_POINTSET_H
