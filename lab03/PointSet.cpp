//
// Created by Kovacs Dani on 29.09.2025.
//

#include "PointSet.h"

#include <iostream>
#include <random>
#include <set>

inline void PointSet::computeDistances() {
    distances.clear();
    int nPoints = points.size();
    for (int i = 0; i < nPoints; i++) {
        for (int j = i + 1; j < nPoints; j++) {
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
    return (n * (n-1)) / 2;
}

void PointSet::printPoints() const {
    for (auto p : points) {
        std::cout << "(" << p.getX() << ", " << p.getY() << ") ";
    }
    std::cout << std::endl;
}

void PointSet::printDistances() const {
    for (auto d : distances) {
        std::cout << d << ' ';
    }
    std::cout << "\n";
}

void PointSet::sortPointsX() {
    std::sort(points.begin(), points.end(), [](const Point &a, const Point &b) { return a.getX() < b.getX();});
}

void PointSet::sortPointsY() {
    std::sort(points.begin(), points.end(), [](const Point &a, const Point &b) { return a.getY() < b.getY();});
}

void PointSet::sortDistances() {
    std::sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    std::set<double> uniqueDistances;
    for (double d : distances) {
        uniqueDistances.insert(d);
    }
    return static_cast<int>(uniqueDistances.size());
}
