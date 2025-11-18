//
// Created by Kovacs Dani on 17.11.2025.
//

#ifndef LAB10_GRADUATIONDAO_H
#define LAB10_GRADUATIONDAO_H

#include <map>
#include <string>
using namespace std;
#include "student.h"
#include <set>

class GraduationDao {
    int year{2023};
    map<int, Student> students;
    set<string> subjects;
public:

    explicit GraduationDao(int year);
    void enrollStudents(const string &filename);
    void readGradesSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
    bool isStudentPassed(const Student& student) const;
    Student findById(int id) const;
    double getAverageBySubject(const string &subject) const;
    bool isEnrolled(int id) const;
};
#endif //LAB10_GRADUATIONDAO_H