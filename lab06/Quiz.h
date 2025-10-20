//
// Created by Kovacs Dani on 20.10.2025.
//

#ifndef LAB6_QUIZ_H
#define LAB6_QUIZ_H
#include "QuizItem.h"

class Quiz {
private:
    int id;
    string name;
    vector<QuizItem> items;
    bool isReady;
public:
    Quiz(int id, const string& name);
    void addItem(const QuizItem& item);
    void finalize();
    bool getIsReady() const;
    const string& getName() const;
    int getId() const;
    const vector<QuizItem>& getItems() const;
    bool loadFromFile(const string& filename);
};

#endif //LAB6_QUIZ_H