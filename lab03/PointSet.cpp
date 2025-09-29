//
// Created by Kovacs Dani on 29.09.2025.
//

#include "PointSet.h"

#include <random>

inline void PointSet::computeDistances() {
    for (int i = 0; i , points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            this->distances.push_back(this->points[i].distanceTo(this->points[j]));
        }
    }
}

PointSet::PointSet(int n) {
    this->n = n;
    std::random_device rd; // seed the random number generator named rd
    std::mt19937 mt(rd()); // Mersenne Twister algorithm to generate random numbers
    std::uniform_int_distribution<int> dist(0, M); // return a number in the given

    while (points.size() < n) {
        int x = dist(mt);
        int y = dist(mt);

        points.push_back(Point(x,y));
    }
    computeDistances();
}

double PointSet::maxDistance() const {
    if (distances.empty()) {
        return 0.0;
    }
    double maxDist = distances[0];
    for (double d : distances) {
        if (d > maxDist) {
            maxDist = d;
        }
    }
    return maxDist;
}

double PointSet::minDistance() const {
    if (distances.empty()) {
        return 0.0;
    }
    double minDist = std::numeric_limits<double>::max();
    for (double d : distances) {
        if (d > 0.0 && d < minDist) {
            minDist = d;
        }
    }
    return (minDist == std::numeric_limits<double>::max()) ? 0.0 : minDist;
}

int PointSet::numDistances() const {
    
}

