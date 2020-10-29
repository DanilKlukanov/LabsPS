#include "Rational.h"
#include "pch.h"

rational_numbers::rational_numbers() : numerator(0), denominator(1) {};

rational_numbers::rational_numbers(int64_t num, int64_t den) {
    this->numerator = num;
    this->denominator = den;
    if (this->denominator == 0) {
        cout << "Warning, do not enter zero in the denominator." << endl;
        numerator = num;
        denominator = 1;
    }
    else if (this->denominator < 0) {
        this->numerator = -num;
        this->denominator = -den;
    }
}

rational_numbers::rational_numbers(double value) {
    double copy_value = value;
    int index;

    if ((int64_t(value) - value) == 0) {
        numerator = int64_t(value);
        denominator = 1;
    }
    else {
        std::ostringstream strs;
        strs << value;
        std::string str = strs.str();
        index = str.length() - (str.find(".") + 1);
        for (int i = 0; i < index; i++) {
            copy_value *= 10;
            denominator *= 10;
        }
        numerator = copy_value;
        reducation();
    }
}

void rational_numbers::reducation() {
    int64_t den = great_common_den(numerator < 0 ? -numerator : numerator, denominator);
    numerator /= den;
    denominator /= den;
}

int64_t rational_numbers::great_common_den(int64_t num, int64_t den) const {
    while (num) {
        int64_t t = den % num;
        den = num;
        num = t;
    }
    return den;
}

string rational_numbers::get_ratioanl_number() {
    return to_string(numerator) + '/' + to_string(denominator);
}

rational_numbers &rational_numbers::operator=(const rational_numbers& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

rational_numbers rational_numbers::operator+(const rational_numbers& other) const {
    if (this->denominator == other.denominator)
        return rational_numbers((this->numerator + other.numerator), this->denominator);
    else
        return rational_numbers((this->numerator * other.denominator + other.numerator * this->denominator), this->denominator * other.denominator);
}

rational_numbers rational_numbers::operator*(const rational_numbers& other) const {
    return rational_numbers(this->numerator * other.numerator, this->denominator * other.denominator);
}

rational_numbers rational_numbers::operator-(const rational_numbers& other) const {
    if (this->denominator == other.denominator)
        return rational_numbers((this->numerator - other.numerator), this->denominator);
    else
        return rational_numbers((this->numerator * other.denominator - other.numerator * this->denominator), this->denominator * other.denominator);
}

rational_numbers rational_numbers::operator/(const rational_numbers& other) const {
    return rational_numbers(this->numerator * other.denominator, this->denominator * other.numerator);
}

rational_numbers rational_numbers::operator-() const {
    return rational_numbers(-this->numerator, this->denominator);
}

bool rational_numbers::operator<(const rational_numbers& other) const {
    return (this->numerator * other.denominator < this->denominator* other.numerator);
}

bool rational_numbers::operator>(const rational_numbers& other) const {
    return (this->numerator * other.denominator > this->denominator * other.numerator);
}

bool rational_numbers::operator>=(const rational_numbers& other) const {
    return (this->numerator * other.denominator >= this->denominator * other.numerator);
}

bool rational_numbers::operator==(const rational_numbers& other) const {
    return (this->numerator == other.numerator && this->denominator == other.denominator);
}

ostream& operator<<(ostream& out, const rational_numbers& rat) {
    return out << rat.numerator << "/" << rat.denominator;
}

rational_numbers rational_numbers::Sqrt() const {
    return rational_numbers(sqrt(numerator) / sqrt(denominator));
}

double rational_numbers::Dec() const {
    return (numerator / denominator);
}

string rational_numbers::GetDec() const {
    return to_string(numerator) + "/" + to_string(denominator);
}
