//
// Created by Kovacs Dani on 22.09.2025.
//

#ifndef LAB1_FUNCTIONS_H
#define LAB1_FUNCTIONS_H
#include <utility>

int countBits(int number);
bool setBits(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
std::pair<double, double> max2(double array[], int numElements);
int countWords(const char* text);
#endif //LAB1_FUNCTIONS_H