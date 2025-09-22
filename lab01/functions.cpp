//
// Created by Kovacs Dani on 22.09.2025.
//

#include "functions.h"

//
// Created by Kovacs Dani on 16.09.2025.
//
#include <cmath>
#include <concepts>
#include <iosfwd>
#include <sstream>

int countBits(int number) {
    int result = 0;
    while (number > 0) {
        result += number & 1;
        number >>= 1;
    }
    return result;
}

bool setBits(int& number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    number |= (1 << order);
    return true;
}

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }

    double sum = 0.0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    return sum / numElements;
}

double stddev(double array[], int numElements) {
    if (numElements ==0) {
        return NAN;
    }
    double mu = mean(array,numElements);
    double sumSquares = 0.0;
    for (int i = 0; i < numElements; i++) {
        double diff = array[i] - mu;
        sumSquares += diff * diff;
    }
    return sqrt(sumSquares / numElements);
}

std::pair<double, double> max2(double array[], int numElements) {
    if (numElements == 0) {
        return {NAN, NAN};
    }
    if (numElements == 1) {
        return {array[0], array[0]};
    }

    double max1 = array[0];
    double max2 = array[1];
    if (max1 < max2) {
        std::swap_ranges(max1, max2);
    }

    for (int i = 2; i < numElements; i++) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        } else if (array[i] > max2) {
            max2 = array[i];
        }
    }
    return {max2, max1};
}

int countWords(std::string text) {
    std::istringstream inputstream(text);
    std::string word;
    int count = 0;

    while (inputstream >> word) {
        count++;
    }
    return count;
}