//
// Created by Kovacs Dani on 17.11.2025.
//

#include "student.h"

Student::Student(int id, const string &firstName = "", const string &lastName = ""): id(id), firstName(firstName), lastName(lastName), average(0.0){}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string & Student::getFirstName() const {
    return firstName;
}

const string & Student::getLastName() const {
    return lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;

}

double Student::getGrade(const string &subject) const {
    return grades.at(subject);
}

const map<string, double> & Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    if (grades.empty()) {
        average = 0.0;
        return;
    }

    double sum = 0.0;
    for (const auto& pair : grades) {
        sum += pair.second;
    }
    average = sum / grades.size();
}

double Student::getAverage() const {
    return average;
}


