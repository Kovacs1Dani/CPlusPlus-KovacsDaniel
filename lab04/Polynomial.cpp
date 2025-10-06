//
// Created by Kovacs Dani on 06.10.2025.
//
#include "Polynomial.h"


Polynomial::Polynomial(int degree, const double coefficients[]) : capacity(degree+1) {
    this->coefficients = new double[capacity];
    if (coefficients != nullptr) {
        for (int i = 0; i <= degree; ++i) {
            this->coefficients[i] = coefficients[i];
        }
    }
}

Polynomial::Polynomial(const Polynomial &that) : capacity(that.capacity),
coefficients(new double[that.capacity]) {
    for (int i = 0; i <= capacity; ++i) {
        this->coefficients[i] = that.coefficients[i];
    }

}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

int Polynomial::degree() const {
    int i = 0;
    while (i < coefficients[i] == 0 && i < capacity) {
        i++;
    }
    return capacity - i -1;
}

double Polynomial::evaluate(double x) const {
    int result = 0.0;
    int power = 1.0;
    for (int i = 0; i < capacity; ++i) {
        result += coefficients[i] * power;
        power *= x;
    }
    return result;
}

Polynomial Polynomial::derivative() const {
    if (capacity <= 1) {
        double zero = 0.0;
        return Polynomial(0, &zero);
    }

    int newDegree = capacity - 2;
    double *derivCoeffs = new double[newDegree + 1];

    for (int i = 1; i < capacity; ++i) {
        derivCoeffs[i - 1] = i * coefficients[i];
    }
    Polynomial result(newDegree, derivCoeffs);
    delete[] derivCoeffs;
    return result;
}

double Polynomial::operator[](int index) const {
    if (index > capacity) return 0;
    return coefficients[capacity - index - 1];
}

Polynomial operator-(const Polynomial &a) {
    double *neg = new double[a.capacity];
    for (int i = 0; i < a.capacity; ++i) {
        neg[i] = -a.coefficients[i];
    }
    Polynomial result(a.capacity -1, neg);
    delete[] neg;
    return result;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    Polynomial result(max(a.degree(), b.degree()), nullptr);
    for (int i = 0; i <= result.degree(); ++i) {
        result.coefficients[result.capacity - i - 1] = a[i] + b[i];
    }
    return result;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial result(max(a.degree(), b.degree()), nullptr);
    for (int i = 0; i <= result.degree(); ++i) {
        result.coefficients[result.capacity - i - 1] = a[i] - b[i];
    }
    return result;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {


}

ostream & operator<<(ostream &out, const Polynomial &what) {
    for (int i = what.degree(); i >= 0; --i) {
        out << what[i] << "x^" << i << " + ";
    }
    return out;
}


