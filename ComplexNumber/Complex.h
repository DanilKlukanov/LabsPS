#pragma once
#include <cstdint>
#include <iostream>
#include <string.h>
#include <sstream>
#include "Rational.h"
using namespace std;

class complex_numbers {
private:
    rational_numbers real;
    rational_numbers imag;

public:
    
    complex_numbers(const rational_numbers& real, const rational_numbers& imag);
    
    complex_numbers(double number);

    complex_numbers();

    rational_numbers get_real();

    rational_numbers get_imag();

    complex_numbers& operator=(const complex_numbers& other);

    complex_numbers operator+(const complex_numbers& other) const;

    complex_numbers operator-(const complex_numbers& other) const;

    complex_numbers operator*(const complex_numbers& other) const;

    complex_numbers operator/(const complex_numbers& other) const;

    complex_numbers& operator+=(const complex_numbers& other);

    complex_numbers& operator*=(const complex_numbers& other);

    complex_numbers& operator-=(const complex_numbers& other);

    complex_numbers& operator/=(const complex_numbers& other);

    complex_numbers operator-() const;

    bool operator==(const complex_numbers& other) const;

    bool operator!=(const complex_numbers& other) const;

    friend ostream& operator<<(ostream& out, const complex_numbers& com);

    rational_numbers Abs() const;

    rational_numbers Arg() const;

    complex_numbers Pow(int ext = 2);
    
    void set_real(double real_num);

    void set_imag(double imag_part);
};