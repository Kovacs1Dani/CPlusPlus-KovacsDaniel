#include "QuizItem.h"
#include <iostream>
using namespace std;

QuizItem::QuizItem(int id, const vector<string>& question, const string& answers, int correctAnswer)
    : id(id), question(question), answers(answers), correctAnswer(correctAnswer) {}

void QuizItem::display() const {
    cout << "\nKérdés #" << id << ":\n";
    for (const auto& line : question) {
        cout << line << endl;
    }
    cout << "Válasz: " << answers << endl;
}

bool QuizItem::checkAnswer(int userAnswer) const {
    return userAnswer == correctAnswer;
}
