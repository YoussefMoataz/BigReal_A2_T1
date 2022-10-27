//
// Created by Youssef Moataz on 10/27/2022.
//

#ifndef BIGREAL_A2_T1_BIGREALHEADER_H
#define BIGREAL_A2_T1_BIGREALHEADER_H
#endif //BIGREAL_A2_T1_BIGREALHEADER_H

#include <iostream>
#include "regex"
#include "BigDecimalInt/BigDecimalIntFunctions.cpp"

using namespace std;
// Prototypes, Constants and Classes

class BigReal {
private:
    BigDecimalInt integerPart;
    BigDecimalInt decimalPart;

    // BDI removes leading zeroes, they are important in decimalPart, I store them
    int decimalLeadingZeroes = 0;
    int realSign;

public:
    inline BigReal(double realNumber = 0.0); // Default constructor
    inline BigReal(string realNumber);

    inline BigReal(BigDecimalInt bigInteger);

    inline BigReal(const BigReal &other); // Copy constructor
    inline BigReal(BigReal &&other); // Move constructor
    inline BigReal &operator=(BigReal &other); // Assignment operator
    inline BigReal &operator=(BigReal &&other); // Move assignment
    inline BigReal operator+(BigReal &other);

    inline BigReal operator-(BigReal &other);

    inline bool operator<(BigReal anotherReal);

    inline bool operator>(BigReal anotherReal);

    inline bool operator==(BigReal anotherReal);

    inline int size();

    inline int sign();

    inline friend ostream &operator<<(ostream &out, BigReal num);

    inline friend istream &operator>>(istream &in, BigReal num);
};

// End of the file