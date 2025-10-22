#include <iostream>

#include "Quiz.h"
#include "User.h"
#include "QuizGame.h"



int main() {

    Quiz quiz1(1, "SUPER QUIZ");
    if (!quiz1.loadFromFile("kerdesek.txt")) return 1;

    User user1(1, "Kovacs Daniel");

    QuizGame game(user1, quiz1);
    game.play();

    user1.showResults();
    return 0;
}
