//
// Created by Kovacs Dani on 20.10.2025.
//

#ifndef LAB6_USER_H
#define LAB6_USER_H
#include <map>
#include <string>

class User {
private:
    int id;
    std::string name;
    std::map<int, double> results;

public:
    User(int id, const std::string& name);
    void addresult(int quizId, double score);
    void showResults() const;
    const std::string& getName() const;
};

#endif //LAB6_USER_H