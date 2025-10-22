//
// Created by Kovacs Dani on 20.10.2025.
//

#ifndef LAB6_QUIZGAME_H
#define LAB6_QUIZGAME_H
#include "Quiz.h"
#include "User.h"

class QuizGame {
private:
    User& user;
    Quiz& quiz;
public:
    QuizGame(User& user, Quiz& quiz);
    void play();
};

#endif //LAB6_QUIZGAME_H