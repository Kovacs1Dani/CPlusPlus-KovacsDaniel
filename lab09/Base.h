//
// Created by Kovacs Dani on 11.11.2025.
//

#ifndef LAB9_BASE_H
#define LAB9_BASE_H
#include <string>
using namespace std;


class fileSystemItem {
protected:
    string name;
    long size;
public:
    fileSystemItem(const string& name, long size = 0): name(name), size(size) {}
    virtual ~fileSystemItem(){}
    string getName() const {return name;}
    virtual long getSize() const = 0;
    virtual void display(int depth = 0) const = 0;
    virtual fileSystemItem* clone() const = 0;
    friend ostream& operator<<(ostream &os, const fileSystemItem& item) {
        item.display();
        return os;
    }
    bool operator<(const fileSystemItem& other) const {
        return name < other.name;
    }
 };

#endif //LAB9_BASE_H