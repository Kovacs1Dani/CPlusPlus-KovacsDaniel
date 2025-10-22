//
// Created by Kovacs Dani on 20.10.2025.
//


#include "QuizGame.h"

#include <iostream>

QuizGame::QuizGame(User &user, Quiz &quiz): user(user), quiz(quiz) {}

void QuizGame::play() {
    if (!quiz.getIsReady()) {
        std::cout << "The quiz is not over yet";
        return;
    }

    std::cout << user.getName() << ", starting the \"" << quiz.getName() << "\" quiz!\n";

    const auto& items = quiz.getItems();
    int correct = 0;

    for (const auto& item : items) {
        item.display();
        std::cout << "Response (1-4): ";
        int ans;
        std::cin >> ans;
        if (item.checkAnswer(ans)) {
            std::cout << "Correct!\n";
            correct++;
        }
        else {
            std::cout << "Wrong answer!\n";
        }
    }

    double score = (double)correct / items.size() * 100;
    std::cout << "\n Score:" << score << "%\n";
    user.addresult(quiz.getId(), score);
}

