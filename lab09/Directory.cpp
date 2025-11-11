//
// Created by Kovacs Dani on 11.11.2025.
//

#include "Directory.h"

#include <iostream>

Directory::Directory(const string &name): fileSystemItem(name) {}

Directory::Directory(const Directory &other): fileSystemItem(other.name) {
    for ( auto child : other.children) {
        children.push_back(child->clone());
    }
}

Directory & Directory::operator=(const Directory &other) {
    if (this != &other) {
        for (auto c : children) delete c;
        children.clear();
        name = other.name;
        for (auto child : children) {
            children.push_back(child->clone());
        }
    }
    return *this;
}

Directory::~Directory() {
    for (auto c : children) {
        delete c;
    }
}

void Directory::add(fileSystemItem *item) {
    children.push_back(item);
}

void Directory::remove(const string &name) {
    auto it = remove_if(children.begin(), children.end(), [&](fileSystemItem* item) {
        if (item->getName() == name) {
            delete item;
            return true;
        }
        return false;
    });
    children.erase(it, children.end());
}

fileSystemItem * Directory::find(const string &name) {
    for (auto c : children) {
        if (c->getName() == name) {
            return c;
        }
        Directory* dir = dynamic_cast<Directory *>(c);
        if (dir) {
            fileSystemItem* found = dir->find(name);
            if (found) return found;
        }
    }
}

long Directory::getSize() const {
    long total = 0;
    for (auto c : children) {
        total += c->getSize();
    }
    return total;
}

void Directory::display(int depth) const {
    cout << string(depth * 2, ' ') << name << "/ (" << getSize() << " bytes)" << endl;
    for (auto child : children) {
        child->display(depth + 1);
    }
}

fileSystemItem * Directory::clone() const {
    return new Directory(*this);
}

Directory & Directory::operator+=(fileSystemItem *item) {
    add(item);
    return *this;
}

Directory & Directory::operator-=(fileSystemItem *item) {
    remove(name);
    return *this;
}


