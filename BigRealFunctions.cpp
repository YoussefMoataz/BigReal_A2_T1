#include "BigRealHeader.h"

// Defining functions, class methods

// Youssef
BigReal::BigReal(double realNumber) {

    // assign the integer part
    integerPart = BigDecimalInt(realNumber);

    string realString = to_string(realNumber);

    string decimalPartString = "";

    // get the decimal point index
    int pointIndex = realString.find('.');
    // get the leading zeroes
    int dec = pointIndex + 1;
    for (; dec < realString.length(); ++dec) {

        if (realString[dec] != '0') {
            break;
        }

        decimalLeadingZeroes++;

    }

    // get the decimal part
    for (; dec < realString.length(); ++dec) {
        decimalPartString += realString[dec];
    }

    // only 6 digits, if less : complete with zeroes
    decimalPart = BigDecimalInt(decimalPartString);

}

// Youssef
BigReal::BigReal(string realNumber) {

    // check if string match the real number syntax
    regex filter("^[+-]?[0-9]+[.]?[0-9]+");
    if (regex_match(realNumber, filter)) {

        string integerPartString = "", decimalPartString = "";

        // get the decimal point index
        int pointIndex = realNumber.find('.');

        // get the integer part
        for (int i = 0; i < pointIndex; ++i) {
            integerPartString += realNumber[i];
        }

        // get the leading zeroes
        int dec = pointIndex + 1;
        for (; dec < realNumber.length(); ++dec) {

            if (realNumber[dec] != '0') {
                break;
            }

            decimalLeadingZeroes++;

        }

        // get the decimal part
        for (; dec < realNumber.length(); ++dec) {
            decimalPartString += realNumber[dec];
        }

        // assign the BDIs
        integerPart = BigDecimalInt(integerPartString);
        decimalPart = BigDecimalInt(decimalPartString);

        // assign the real sign
        realSign = integerPart.sign();

    } else {
        cout << "Invalid Input";
    }

}

// Youssef
BigReal::BigReal(BigDecimalInt bigInteger) {

    integerPart = bigInteger;
    decimalPart = BigDecimalInt(0);

}

// Copy constructor
BigReal::BigReal(const BigReal &other) {

}

// Move constructor
BigReal::BigReal(BigReal &&other) {

}

// Assignment operator
BigReal &BigReal::operator=(BigReal &other) {

}

// Move assignment
BigReal &BigReal::operator=(BigReal &&other) {

}

// Hassan
BigReal BigReal::operator+(BigReal &other) {

}

// Hassan
BigReal BigReal::operator-(BigReal &other) {

}

// Mohamed
bool BigReal::operator<(BigReal anotherReal) {

}

// Mohamed
bool BigReal::operator>(BigReal anotherReal) {

}

// Mohamed
bool BigReal::operator==(BigReal anotherReal) {

}

// Youssef
int BigReal::size() {

    return integerPart.size() + decimalPart.size() + 1;

}

// Youssef
int BigReal::sign() {

    return realSign;

}

// Youssef
ostream &operator<<(ostream &out, BigReal num) {

    // print the integer part, decimal point, leading zeroes, decimal part
    out << num.integerPart.getDecimalStr() << "." << string(num.decimalLeadingZeroes, '0')
        << num.decimalPart.getDecimalStr();

    return out;

}

// Youssef
istream &operator>>(istream &in, BigReal num) {

}

// End of the file