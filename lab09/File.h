//
// Created by Kovacs Dani on 11.11.2025.
//

#ifndef LAB9_FILE_H
#define LAB9_FILE_H
#include <iostream>
#include <string>

#include "Base.h"
using namespace std;

class File : public fileSystemItem {
public:
    File(const std::string& name, long size) : fileSystemItem(name, size) {}
    virtual long getSize() const override {return size;}
    virtual void display(int depth = 0) const override {
        cout << string(depth * 3, ' ') << name << " (" << size << " bytes)" << endl;
    };
    virtual fileSystemItem* clone() const override {
        return new File(*this);
    }

};


#endif //LAB9_FILE_H