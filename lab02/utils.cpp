//
// Created by Kovacs Dani on 23.09.2025.
//

#include "utils.h"

#include <fstream>
#include <iosfwd>
#include <iostream>

#include "Point.h"

double distance(const Point &a, const Point &b) {
        double distance = sqrt((b.getX() - a.getX())*(b.getX() - a.getX()) + (b.getY() - a.getY())*(b.getY() - a.getY()));
        return distance;
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
        double edges[6] = {
                distance(a, b),
                distance(a,c),
                distance(a,d),
                distance(b,c),
                distance(b,d),
                distance(c, d),
            };

        std::sort(edges, edges + 6);
        return edges[0] == edges[3] && edges[4] == edges[5] && edges[1] > edges[5];
}

void testIsSquare(const char *filename) {
        std::ifstream beolvas(filename);

        if (!beolvas.is_open()) {
                std::cerr << "Error when reading from file! " << filename << std::endl;
                return;
        }

        int x1, y1, x2, y2, x3, y3, x4, y4;

        while (beolvas >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
                Point A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4);

                std::cout << "Points:\n ";
                A.print();
                B.print();
                C.print();
                D.print();

                if (isSquare(A, B, C, D)) {
                        std::cout << "YES" << std::endl;
                } else {
                        std::cout << "NO" << std::endl;
                }

                std::cout << "_______________________" << std::endl;
        }
        beolvas.close();
}

Point* createArray(int numPoints) {
        if (numPoints <=0) return nullptr;
        Point* pointsArray = new Point[numPoints];

        std::srand(0);
        for (int i = 0; i < numPoints; i++) {
                int x = std::rand() % 2001;
                int y = std::rand() % 2001;
                pointsArray[i] = Point(x,y);
        }
        return pointsArray;
}

void printArray(Point *points, int numPoints) {
        for (int i = 0; i < numPoints; i++) {
                points[i].print();
        }
}

std::pair<Point, Point> closestPoints(Point *points, int numPoints) {
        if (numPoints < 2) throw std::invalid_argument("At least two points required");

        double minDistance = std::numeric_limits<double>::max();
        std::pair<Point, Point> closestPair(points[0], points[1]);

        for (int i = 0; i < numPoints; i++) {
                for (int j = i + 1; j < numPoints; j++) {
                        double d = distance(points[i], points[j]);
                        if (d < minDistance) {
                                minDistance = d;
                                closestPair = { points[i], points[j] };
                        }
                }
        }
        return closestPair;
}

std::pair<Point, Point> farthestPoints(Point *points, int numPoints) {
        if (numPoints < 2) throw std::invalid_argument("At least two points required");

        double maxDistance = std::numeric_limits<double>::lowest();
        std::pair<Point, Point> farthestPair(points[0], points[1]);

        for (int i = 0; i < numPoints; i++) {
                for (int j = i + 1; j < numPoints; j++) {
                        double d = distance(points[i], points[j]);
                        if (d > maxDistance) {
                                maxDistance = d;
                                farthestPair = {points[i], points[j]};
                        }
                }
        }
        return farthestPair;
}

double distanceFromOrigin(const Point& p) {
        return static_cast<double>(p.getX()) * p.getX() + static_cast<double>(p.getY()) * p.getY();
}

Point* farthestPointsFromOrigin(Point* points, int numPoints) {
        if (numPoints<=0) return nullptr;


        using Entry = std::pair<double, int>;
        auto cmp = [](const Entry& a, const Entry& b) {
                return a.first > b.first;
        };

        std::priority_queue<Entry, std::vector<Entry>, decltype(cmp) > minHeap(cmp);

        for (int i = 0; i < numPoints; i++) {
                double d = distanceFromOrigin(points[i]);
                if ((int)minHeap.size() < 10) {
                        minHeap.push({d, i});
                } else if (d > minHeap.top().first) {
                        minHeap.pop();
                        minHeap.push({d, i});
                }
        }

        int resultSize = std::min(10, numPoints);
        Point* result = new Point[resultSize];

        for (int i = resultSize - 1; i >= 0; i--) {
                result[i] = points[minHeap.top().second];
                minHeap.pop();
        }
        return result;
}

void deletePoints(Point *points) {
        delete[] points;
}
