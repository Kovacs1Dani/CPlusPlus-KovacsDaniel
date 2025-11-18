//
// Created by Kovacs Dani on 17.11.2025.
//

#ifndef LAB10_STUDENT_H
#define LAB10_STUDENT_H

#include <iomanip>
#include <string>
#include <map>
using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName);
    int getId() const;
    void setId(int id);
    const string &getFirstName()const;
    const string &getLastName() const;
    void addGrade(const string& subject, double grade);
    double getGrade(const string& subject) const;
    const map<string, double> &getGrades() const;
    void computeAverage();
    double getAverage() const;
    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "ID: " << student.id
           << ", Nev: " << student.lastName << " " << student.firstName
           << ", Atlag: " << fixed << setprecision(2) << student.average;

        return os;
    }
};
#endif //LAB10_STUDENT_H