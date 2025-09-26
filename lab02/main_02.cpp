#include <iostream>

#include "Point.h"
#include "utils.h"

using namespace std;
int main() {

    Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<" )"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<" )"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<" )"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<" )"<<endl;
    delete pp1;
    delete pp2;
    testIsSquare("points.txt");

    int n = 20;
    Point* array = createArray(n);
    /*for (int i = 0; i < n; i++) {
        array[i].print();
    }*/
    printArray(array, n);

    auto result1 = farthestPoints(array, n);
    auto result2 = closestPoints(array, n);
    cout << "Farthest points:\n";
    result1.first.print();
    result1.second.print();
    cout << "Closest points:\n";
    result2.first.print();
    result2.second.print();

    Point* farthest = farthestPointsFromOrigin(array, n);

    cout << "Top 10 farthest from origin:" << endl;
    for (int i = 0; i < std::min(10, n); i++) {
        farthest[i].print();
    }
    printArray(farthest, std::min(10, n));

    deletePoints(array);
    deletePoints(farthest);
    return 0;
}
