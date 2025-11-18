//
// Created by Kovacs Dani on 18.11.2025.
//

#include "StudentService.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    return dao->isEnrolled(id);
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    vector<string> subjectNames;
    try {
        Student s = dao->findById(id);
        const auto& grades = s.getGrades();
        for ( const auto& pair : grades) {
            subjectNames.push_back(pair.first);
        }
    } catch (const out_of_range& e) {

    }
    return subjectNames;
}

double StudentServiceImpl::getResultBySubject(int id, const std::string &subject) const {
    Student s = dao->findById(id);
    return s.getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    Student s = dao->findById(id);
    return s.getAverage();
}

bool StudentServiceImpl::isPassed(int id) const {
    try {
        Student s = dao->findById(id);
        return dao->isStudentPassed(s);
    }catch (out_of_range& e) {
        return false;
    }
}

