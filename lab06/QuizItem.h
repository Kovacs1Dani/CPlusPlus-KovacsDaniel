//
// Created by Kovacs Dani on 20.10.2025.
//

#ifndef LAB6_QUIZITEM_H
#define LAB6_QUIZITEM_H

#include <vector>
#include <string>
using std::vector;
using std::string;

class QuizItem {
private:
    int id;
    vector<string> question;
    string answers;
    int correctAnswer;
public:
    QuizItem(int id, const vector<string>& question, const string& answers, int correctAnswer);
    void display() const;
    bool checkAnswer(int userAnswer) const;
};


#endif //LAB6_QUIZITEM_H