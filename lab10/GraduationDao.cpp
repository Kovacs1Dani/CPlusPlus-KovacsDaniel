//
// Created by Kovacs Dani on 17.11.2025.
//

#include "GraduationDao.h"
#include "student.h"
#include <fstream>
#include <iostream>


GraduationDao::GraduationDao(int year): year(year) {}

void GraduationDao::enrollStudents(const string &filename) {
    ifstream file("names.txt");
    if (!file.is_open()) {
        cerr << "Hiba: Nem sikerult megnyitni a fajlt: " << filename << endl;
        return;
    }

    int id;
    string lastName, firstName;
    while (file >> id >> lastName >> firstName) {
        students.emplace(id, Student(id, firstName, lastName));
    }
    file.close();
}

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {
    subjects.insert(subject);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Hiba: Nem sikerult megnyitni a fajlt: " << filename << endl;
        return;
    }

    int id;
    double grade;

    while ( file >> id >> grade) {
        try {
            Student& student = students.at(id);
            student.addGrade(subject, grade);
        }catch (const out_of_range& e) {
            cerr << "Figyelmeztetes: Nem talalhato diak " << id << " ID-val a(z) "
                     << filename << " fajlbol." << endl;
        }
    }
    file.close();
}

void GraduationDao::computeAverage() {
    for (auto& pair : students) {
        pair.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}


int GraduationDao::numPassed() const {
     int count = 0;
    for (const auto& pair : students) {
        if (isStudentPassed(pair.second)) {
            count++;
        }
    }
    return count;
}

bool GraduationDao::isStudentPassed(const Student &student) const {
    if (student.getGrades().size() != subjects.size()) {
        return false;
    }
    if (student.getAverage() < 6.0) {
        return false;
    }
    for (const auto& gradePair : student.getGrades()) {
        if (gradePair.second < 5.0) {
            return false;
        }
    }
    return true;
}

Student GraduationDao::findById(int id) const {
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double total = 0.0;
    int count = 0;
    for (const auto& pair : students) {
        try {
            total += pair.second.getGrade(subject);
            count++;
        } catch (const out_of_range& e) {
        }
    }

    if (count == 0) {
        return 0.0;
    }
    return total / count;
}

bool GraduationDao::isEnrolled(int id) const {
    return students.count(id) > 0;
}
