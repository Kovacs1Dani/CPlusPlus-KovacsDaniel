//
// Created by Kovacs Dani on 18.11.2025.
//

#ifndef LAB10_STUDENTSERVICE_H
#define LAB10_STUDENTSERVICE_H
#include <vector>

#include "GraduationDao.h"
using namespace std;

class StudentService {
public:
    virtual ~StudentService(){}

    virtual bool isEnrolled (int id) const = 0;
    virtual double getResultBySubject(int id, const std::string& subject) const = 0;
    virtual std::vector<std::string> getSubjects(int id) const = 0;
    virtual double getAverage (int id) const = 0;
    virtual bool isPassed(int id) const = 0;

};


class StudentServiceImpl : public StudentService {
private:
    GraduationDao *dao;
public:
    StudentServiceImpl(GraduationDao * dao): dao(dao){}

    bool isEnrolled(int id) const override;
    vector<string> getSubjects(int id) const override;
    double getResultBySubject(int id, const std::string &subject) const override;
    double getAverage(int id) const override;
    bool isPassed(int id) const override;
};

#endif //LAB10_STUDENTSERVICE_H