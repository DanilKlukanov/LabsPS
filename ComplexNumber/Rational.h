#pragma once
#include <cstdint>
#include <iostream>
#include <string.h>
#include <sstream>
#include <exception>
using namespace std;

class rational_numbers {
private:
    int64_t numerator = 0, denominator = 1;

public:
    rational_numbers();

    rational_numbers(int64_t num, int64_t den);

    rational_numbers(double value);

    void reducation();

    int64_t great_common_den(int64_t num, int64_t den) const;

    string get_ratioanl_number();

    rational_numbers& operator=(const rational_numbers& other);

    rational_numbers operator+(const rational_numbers& other) const;

    rational_numbers operator*(const rational_numbers& other) const;

    rational_numbers operator-(const rational_numbers& other) const;

    rational_numbers operator/(const rational_numbers& other) const;

    rational_numbers operator-() const;

    bool operator<(const rational_numbers& other) const;

    bool operator>(const rational_numbers& other) const;

    bool operator>=(const rational_numbers& other) const;

    bool operator==(const rational_numbers& other) const;

    friend ostream& operator<<(ostream& out, const rational_numbers& rat);

    rational_numbers Sqrt() const;

    double Dec() const;

    string GetDec() const;
};