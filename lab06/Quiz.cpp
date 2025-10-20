//
// Created by Kovacs Dani on 20.10.2025.
//
#include "Quiz.h"
using namespace std;
#include <iostream>


Quiz::Quiz(int id, const string &name): id(id), name(name), isReady(false) {}

void Quiz::addItem(const QuizItem &item) {
    if (!isReady) items.push_back(item);
    else {
        cout << "The quiz is already over!";
    }
}

void Quiz::finalize() {
    isReady = true;
}

bool Quiz::getIsReady() const {
    return isReady;
}

const string & Quiz::getName() const {
    return name;
}

int Quiz::getId() const {
    return id;
}

const vector<QuizItem> & Quiz::getItems() const {
    return items;
}

bool Quiz::loadFromFile(const string &filename) {

}
