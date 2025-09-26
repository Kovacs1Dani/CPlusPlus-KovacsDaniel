//
// Created by Kovacs Dani on 23.09.2025.
//

#ifndef LAB2_UTILS_H
#define LAB2_UTILS_H
#include <utility>

#include "Point.h"

void testIsSquare(const char* filename);
double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
std::pair<Point, Point> closestPoints(Point* points, int numPoints);
std::pair<Point, Point> farthestPoints(Point* points, int numPoints);
double distanceFromOrigin(const Point& p);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);

#endif //LAB2_UTILS_H