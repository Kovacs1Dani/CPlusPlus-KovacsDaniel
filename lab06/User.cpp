//
// Created by Kovacs Dani on 20.10.2025.
//

#include <iostream>
using namespace std;

#include "User.h"
User::User(int id, const std::string &name): id(id), name(name) {}

void User::addresult(int quizId, double score) {
    results[quizId] = score;
}

void User::showResults() const {
    cout << "\n " << name << " results:\n";
    if (results.empty()) {
        cout << "No saved results\n";
        return;
    }
    for (const auto& [quizId, score] : results) {
        cout << "Quiz #" << quizId << " -> " << score << "%\n";
    }
}

const std::string &User::getName() const {
    return name;
}


