//
// Created by Kovacs Dani on 11.11.2025.
//

#ifndef LAB9_DIRECTORY_H
#define LAB9_DIRECTORY_H
#include <vector>

#include "Base.h"
using namespace std;

class Directory : fileSystemItem {
private:
    vector<fileSystemItem*> children;
public:
    Directory(const string& name);

    Directory(const Directory& other);

    Directory& operator=(const Directory& other);

    ~Directory() override;
    void add(fileSystemItem* item);
    void remove(const string& name);
    fileSystemItem* find(const string& name);
    long getSize() const override;
    void display(int depth = 0) const override;
    fileSystemItem* clone() const override;
    Directory& operator+=(fileSystemItem* item);
    Directory& operator-=(fileSystemItem* item);
};


#endif //LAB9_DIRECTORY_H