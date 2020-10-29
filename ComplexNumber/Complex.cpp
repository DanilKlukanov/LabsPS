#include "Rational.h"
#include "Complex.h"
#include "pch.h"

complex_numbers::complex_numbers(const rational_numbers& real, const rational_numbers& imag) {
    this->real = real;
    this->imag = imag;
}

complex_numbers::complex_numbers(double number) : real(number), imag(0) {}

complex_numbers::complex_numbers() : real(0), imag(0) {};

rational_numbers complex_numbers::get_real() {
    return real;
}

rational_numbers complex_numbers::get_imag() {
    return imag;
}

complex_numbers &complex_numbers::operator=(const complex_numbers& other) {
    real = other.real;
    imag = other.imag;
    return *this;
}
/*
complex_numbers &complex_numbers::operator=(rational_numbers number) {
    real = number;
    imag = 0;
    return *this;
}
*/
complex_numbers complex_numbers::operator+(const complex_numbers& other) const {
    rational_numbers new_real = this->real + other.real;
    rational_numbers new_imag = this->imag + other.imag;
    return complex_numbers(new_real, new_imag);
}

complex_numbers complex_numbers::operator-(const complex_numbers& other) const {
    rational_numbers new_real = this->real - other.real;
    rational_numbers new_image = this->imag - other.imag;
    return complex_numbers(new_real, new_image);
}

complex_numbers complex_numbers::operator*(const complex_numbers& other) const {
    rational_numbers new_real = this->real * other.real - this->imag * other.imag;
    rational_numbers new_image = this->real * other.imag + this->imag * other.real;
    return complex_numbers(new_real, new_image);
}

complex_numbers complex_numbers::operator/(const complex_numbers& other) const {
    rational_numbers new_real = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
    rational_numbers new_imag = (other.real * imag - other.imag * real) / (other.real * other.real + other.imag * other.imag);
    return complex_numbers(new_real, new_imag);
}

complex_numbers &complex_numbers::operator+=(const complex_numbers& other) {
    *this = *this + other;
    return *this;
}

complex_numbers &complex_numbers::operator*=(const complex_numbers& other) {
    *this = *this * other;
    return *this;
}

complex_numbers &complex_numbers::operator-=(const complex_numbers& other) {
    *this = *this - other;
    return *this;
}

complex_numbers &complex_numbers::operator/=(const complex_numbers& other) {
    *this = *this / other;
    return *this;
}

complex_numbers complex_numbers::operator-() const {
    return complex_numbers(-this->real, -this->imag);
}

bool complex_numbers::operator==(const complex_numbers& other) const {
    return (this->real == other.real && this->imag == other.imag);
}

bool complex_numbers::operator!=(const complex_numbers& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& out, const complex_numbers& com) {
    return out << "( " << com.real << ", " << com.imag << " )";
}

rational_numbers complex_numbers::Abs() const {
    return (this->real * this->real + this->imag * this->imag).Sqrt();
}

rational_numbers complex_numbers::Arg() const {
    const double Pi = acos(-1);
    double atan_result = atan(imag.Dec() / real.Dec());
    if (real > 0) {
        return atan_result;
    } else if (real < 0 && imag >= 0) {
        return Pi + atan_result;
    } else if (real < 0 && imag < 0) {
        return -Pi + atan_result;
    } else if (real == 0 && imag > 0) {
        return Pi / 2;
    } else if (real == 0 && imag < 0) {
        return -(Pi / 2);
    }
}

complex_numbers complex_numbers::Pow(int ext) {
    auto real = this->real;
    auto imag = this->imag;
    complex_numbers a(real, imag);
    for (int i = 1; i < ext; i++) {
        a *= complex_numbers(real, imag);
    }
    return a;
}

void complex_numbers::set_real(double real_num) {
    this->real = real;
}

void complex_numbers::set_imag(double imag_part) {
    this->imag = imag;
}
/*
complex_numbers complex_numbers::operator+(rational_numbers num) {
    return complex_numbers(real + num, imag);
}

complex_numbers &complex_numbers::operator+=(rational_numbers num) {
    *this = *this + num;
    return *this;
}

complex_numbers complex_numbers::operator-(rational_numbers num) {
    return complex_numbers(real - num, imag);
}

complex_numbers &complex_numbers::operator-=(rational_numbers num) {
    *this = *this - num;
    return *this;
}

complex_numbers complex_numbers::operator*(rational_numbers num) {
    return complex_numbers(real * num, imag * num);
}

complex_numbers &complex_numbers::operator*=(rational_numbers num) {
    *this = *this * num;
    return *this;
}

complex_numbers complex_numbers::operator/(rational_numbers num) {
    return complex_numbers(real / num, imag / num);
}

complex_numbers &complex_numbers::operator/=(rational_numbers num) {
    *this = *this * num;
    return *this;
}
*/