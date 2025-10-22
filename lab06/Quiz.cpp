//
// Created by Kovacs Dani on 20.10.2025.
//
#include "Quiz.h"

#include <fstream>
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
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "❌ Nem sikerült megnyitni a fájlt: " << filename << endl;
        return false;
    }

    string line;
    int idCounter = 1;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line[0] == 'Q') {
            vector<string> questionLines;
            questionLines.push_back(line.substr(2));

            string answersCombined;
            string correctStr;

            // több A sor kezelése
            while (getline(file, line)) {
                if (line.empty()) continue;

                if (line[0] == 'A') {
                    if (!answersCombined.empty()) answersCombined += "\n";
                    answersCombined += line.substr(2);
                } else if (isdigit(line[0])) {
                    // ez lesz a helyes válasz sorszáma
                    correctStr = line;
                    break;
                } else if (line[0] == 'Q') {
                    // ha valamiért új kérdés kezdődik szám nélkül
                    cerr << "⚠️ Hiányzik helyes válasz a kérdés #" << idCounter << " után!\n";
                    // visszalépünk egy sort, hogy a következő Q feldolgozható legyen
                    file.seekg(-static_cast<int>(line.size()) - 1, ios::cur);
                    break;
                }
            }

            int correctIndex = 0;
            if (!correctStr.empty()) {
                try {
                    correctIndex = stoi(correctStr);
                } catch (...) {
                    cerr << "⚠️ Hibás helyes válasz formátum (#" << idCounter << "): '" << correctStr << "'\n";
                    correctIndex = 0;
                }
            } else {
                cerr << "⚠️ Hiányzik helyes válasz szám (#" << idCounter << ")\n";
                continue;
            }

            addItem(QuizItem(idCounter++, questionLines, answersCombined, correctIndex));
        }
    }

    finalize();
    return true;
}