#include "BigRealHeader.h"

// Defining functions, class methods

// Youssef
BigReal::BigReal(double realNumber) {


    string realString = to_string(realNumber);

    string decimalPartString = "";

    // get the decimal point index
    int pointIndex = realString.find('.');

    string ipString;
    for (int i = 0; i < pointIndex; ++i) {
        ipString += realString[i];
    }
    // assign the integer part
    integerPart = BigDecimalInt(ipString);

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
    regex filter1("^[+-]?[0-9]+");
    regex filter2("^[+-]?[0-9]+[.][0]$");
    regex filter3("^[+-]?[0-9]+[.][0-9]+");

    if (regex_match(realNumber, filter1)) {

        // assign the BDIs
        integerPart = BigDecimalInt(realNumber);
        decimalPart = BigDecimalInt("0");

        // assign the real sign
        realSign = integerPart.sign();

    } else if (regex_match(realNumber, filter2)) {

        string integerPartString = "";
        // get the decimal point index
        int pointIndex = realNumber.find('.');

        // get the integer part
        for (int i = 0; i < pointIndex; ++i) {
            integerPartString += realNumber[i];
        }

        // assign the BDIs
        integerPart = BigDecimalInt(integerPartString);
        decimalPart = BigDecimalInt("0");

        // assign the real sign
        realSign = integerPart.sign();

    } else if (regex_match(realNumber, filter3)) {

        string integerPartString = "", decimalPartString = "";

        // get the decimal point index
        int pointIndex = realNumber.find('.');

        // get the integer part
        for (int i = 0; i < pointIndex; ++i) {
            integerPartString += realNumber[i];
        }

//        cout << "IPS Cons :" << integerPartString << endl;
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
//        if (integerPartString == "0") {
//            integerPart = BigDecimalInt("0");
//        } else {
//            integerPart = BigDecimalInt(integerPartString);
//        }
        integerPart = BigDecimalInt(integerPartString);
        decimalPart = BigDecimalInt(decimalPartString);

        // assign the real sign
        realSign = integerPart.sign();


    } else {
        cout << "Invalid Real Input";
    }

}

// Youssef
BigReal::BigReal(BigDecimalInt bigInteger) {

    // assign the real part with the BDI
    integerPart = bigInteger;
    // assign the decimal part with zero
    decimalPart = BigDecimalInt("0");
    // assign the sign
    realSign = bigInteger.sign();

}

// Youssef
// Copy constructor
BigReal::BigReal(const BigReal &other) {

    // assign this (LHS object)
    this->integerPart = other.integerPart;
    this->decimalPart = other.decimalPart;
    this->decimalLeadingZeroes = other.decimalLeadingZeroes;
    this->realSign = other.realSign;

}

// Youssef
// Move constructor
BigReal::BigReal(BigReal &&other) {

    // assign this (LHS object)
    this->integerPart = other.integerPart;
    this->decimalPart = other.decimalPart;
    this->decimalLeadingZeroes = other.decimalLeadingZeroes;
    this->realSign = other.realSign;

    // remove "other"
    other.integerPart = BigDecimalInt("0");
    other.decimalPart = BigDecimalInt("0");
    other.decimalLeadingZeroes = 0;
    other.realSign = 0;

}

// Youssef
// Assignment operator
BigReal &BigReal::operator=(BigReal &other) {

    // assign this (LHS object)
    this->integerPart = other.integerPart;
    this->decimalPart = other.decimalPart;
    this->decimalLeadingZeroes = other.decimalLeadingZeroes;
    this->realSign = other.realSign;

    return *this;
}

// Move assignment
BigReal &BigReal::operator=(BigReal &&other) {

    // assign this (LHS object)
    this->integerPart = other.integerPart;
    this->decimalPart = other.decimalPart;
    this->decimalLeadingZeroes = other.decimalLeadingZeroes;
    this->realSign = other.realSign;

    // remove "other"
    other.integerPart = BigDecimalInt("0");
    other.decimalPart = BigDecimalInt("0");
    other.decimalLeadingZeroes = 0;
    other.realSign = 0;

    return *this;
}

// Hassan
BigReal BigReal::operator+(BigReal &other) {
    //definning variables
    BigDecimalInt intPart1 = this->integerPart;
    BigDecimalInt intPart2 = other.integerPart;
    int sign1 = intPart1.sign();
    int sign2 = intPart2.sign();
//    cout << parseSign(sign1) << parseSign(sign2) << " signs" << endl;
    int leadingZeros1 = this->decimalLeadingZeroes;
    int leadingZeros2 = other.decimalLeadingZeroes;
    int AddedZeros = 0;
    int BiggestSize;
    string decPart1 = this->decimalPart.getNumber();
    string decPart2 = other.decimalPart.getNumber();

    for (int i = 0; i < leadingZeros1; i++) {
        decPart1 = "0" + decPart1;
    }
    for (int i = 0; i < leadingZeros2; i++) {
        decPart2 = "0" + decPart2;
    }
    if (decPart1.size() > decPart2.size()) {
        BiggestSize = decPart1.size();
        AddedZeros = decPart1.size() - decPart2.size();
        for (int i = 0; i < AddedZeros; i++) {
            decPart2 = decPart2 + "0";
        }
    } else if (decPart2.size() > decPart1.size()) {
        BiggestSize = decPart2.size();
        AddedZeros = decPart2.size() - decPart1.size();
        for (int i = 0; i < AddedZeros; i++) {
            decPart1 = decPart1 + "0";
        }
    }
    BiggestSize = decPart1.size();
    BigDecimalInt B1 = (parseSign(sign1) + intPart1.getNumber()) + decPart1;
    BigDecimalInt B2 = (parseSign(sign2) + intPart2.getNumber()) + decPart2;
    BigDecimalInt Summed;
    string decPartStr = "", intPartStr = "", Result;
    Summed = B1 + B2;
//    cout << parseSign(Summed.sign()) << endl;
    int i = Summed.size() - 1;
    while (i > Summed.size() - BiggestSize - 1) {
        if (Summed.getNumber()[i] >= '0' && Summed.getNumber()[i] <= '9') {
            decPartStr = Summed.getNumber()[i] + decPartStr;

        }
        i--;
    }
    i = 0;
    while (i < Summed.size() - BiggestSize) {
        intPartStr += Summed.getNumber()[i];
        i++;
    }

//    cout << intPartStr << " IPS" << endl;
    if (intPartStr.size() == 0) {
//        if (Summed.sign() < 0) {
            intPartStr += "0";
//        }
        for (int j = 0; j < BiggestSize - (decPartStr.size() - 1) - 1; i++) {
            decPartStr = "0" + decPartStr;
        }
    }
//    cout << "Int " << intPartStr << endl;
//    cout << parseSign(Summed.sign()) << " sign" << endl;
    string test = parseSign(Summed.sign()) + intPartStr + "." + decPartStr;
//     cout<<test<<endl;
    // cout<<test.length()<<endl;
    BigReal FinalResult = BigReal(test);
    return FinalResult;
}

// Hassan
BigReal BigReal::operator-(BigReal &other) {
    //definning variables
    BigDecimalInt intPart1 = this->integerPart;
    BigDecimalInt intPart2 = other.integerPart;
    int sign1 = intPart1.sign();
    int sign2 = intPart2.sign();
    int leadingZeros1 = this->decimalLeadingZeroes;
    int leadingZeros2 = other.decimalLeadingZeroes;
    int AddedZeros = 0;
    int BiggestSize;
    string decPart1 = this->decimalPart.getNumber();
    string decPart2 = other.decimalPart.getNumber();
    for (int i = 0; i < leadingZeros1; i++) {
        decPart1 = "0" + decPart1;
    }
    for (int i = 0; i < leadingZeros2; i++) {
        decPart2 = "0" + decPart2;
    }
    if (decPart1.size() > decPart2.size()) {
        BiggestSize = decPart1.size();
        AddedZeros = decPart1.size() - decPart2.size();
        for (int i = 0; i < AddedZeros; i++) {
            decPart2 = decPart2 + "0";
        }
    } else if (decPart2.size() > decPart1.size()) {
        BiggestSize = decPart2.size();
        AddedZeros = decPart2.size() - decPart1.size();
        for (int i = 0; i < AddedZeros; i++) {
            decPart1 = decPart1 + "0";
        }
    }
    BiggestSize = decPart1.size();
    BigDecimalInt B1 = (parseSign(sign1) + intPart1.getNumber()) + decPart1;
    BigDecimalInt B2 = (parseSign(sign2) + intPart2.getNumber()) + decPart2;
    BigDecimalInt Summed;
    string decPartStr = "", intPartStr = "", Result;
    Summed = B1 - B2;
    int i = Summed.size() - 1;
    while (i > Summed.size() - BiggestSize - 1) {
        if (Summed.getNumber()[i] >= '0' && Summed.getNumber()[i] <= '9') {
            decPartStr = Summed.getNumber()[i] + decPartStr;

        }
        i--;
    }
    i = 0;
    while (i < Summed.size() - BiggestSize) {
        intPartStr += Summed.getNumber()[i];
        i++;
    }

    if (intPartStr.size() == 0) {
        intPartStr += "0";
        for (int j = 0; j < BiggestSize - (decPartStr.size() - 1) - 1; i++) {
            decPartStr = "0" + decPartStr;
        }
    }
    string test = parseSign(Summed.sign()) + intPartStr + "." + decPartStr;
    BigReal FinalResult = BigReal(test);
    return FinalResult;
}


// Mohamed
bool BigReal::operator<(BigReal anotherReal) {
    if (integerPart < anotherReal.integerPart) {
        return true;
    } else if (integerPart == anotherReal.integerPart) {
        if (decimalPart < anotherReal.decimalPart) {
            return true;
        }
    }
    return false;
}

// Mohamed
bool BigReal::operator>(BigReal anotherReal) {
    if (integerPart > anotherReal.integerPart) {
        return true;
    } else if (integerPart == anotherReal.integerPart) {
        if (decimalPart > anotherReal.decimalPart) {
            return true;
        }
    }
    return false;
}

// Mohamed
bool BigReal::operator==(BigReal anotherReal) {
    if (integerPart == anotherReal.integerPart and decimalPart == anotherReal.decimalPart) {
        return true;
    } else {
        return false;
    }

}

// Youssef
int BigReal::size() {

    // the sum of sizes of integer and decimal parts
    return integerPart.size() + decimalPart.size() + 1;

}

// Youssef
int BigReal::sign() {

    // the sign from integer BDI
    return realSign;

}

// Youssef
ostream &operator<<(ostream &out, BigReal num) {

    // print the integer part, decimal point, leading zeroes, decimal part
    if (!num.integerPart.sign()) {
        out << "-";
    }
//    out << num.integerPart.sign();
    out << num.integerPart.getNumber();
//    if (num.integerPart.sign() != 0){
//        out << "0";
//    }
    out << "." << string(num.decimalLeadingZeroes, '0')
        << num.decimalPart.getNumber();

    return out;

}

// Youssef
istream &operator>>(istream &in, BigReal &num) {

    bool validBigReal = false;
    string brInputString;

    while (!validBigReal) {

        cout << "Enter a big real :" << endl;
        cin >> brInputString;

        // check if string match the real number syntax
        regex filter1("^[+-]?[0-9]+");
        regex filter2("^[+-]?[0-9]+[.][0]");
        regex filter3("^[+-]?[0-9]+[.]?[0-9]+");

        if (regex_match(brInputString, filter1)) {

            // assign the BDIs
            num.integerPart = BigDecimalInt(brInputString);
            num.decimalPart = BigDecimalInt(0);

            // assign leading zeroes
            num.decimalLeadingZeroes = 0;

            // assign the real sign
            num.realSign = num.integerPart.sign();

            validBigReal = true;

        } else if (regex_match(brInputString, filter2)) {

            string integerPartString = "";
            // get the decimal point index
            int pointIndex = brInputString.find('.');

            // get the integer part
            for (int i = 0; i < pointIndex; ++i) {
                integerPartString += brInputString[i];
            }

            // assign the BDIs
            num.integerPart = BigDecimalInt(integerPartString);
            num.decimalPart = BigDecimalInt(0);

            // assign leading zeroes
            num.decimalLeadingZeroes = 0;
            // assign the real sign
            num.realSign = num.integerPart.sign();

            validBigReal = true;

        } else if (regex_match(brInputString, filter3)) {

            string integerPartString = "", decimalPartString = "";

            // get the decimal point index
            int pointIndex = brInputString.find('.');

            // get the integer part
            for (int i = 0; i < pointIndex; ++i) {
                integerPartString += brInputString[i];
            }

            // get the leading zeroes
            int dec = pointIndex + 1;
            for (; dec < brInputString.length(); ++dec) {

                if (brInputString[dec] != '0') {
                    break;
                }

                num.decimalLeadingZeroes++;

            }

            // get the decimal part
            for (; dec < brInputString.length(); ++dec) {
                decimalPartString += brInputString[dec];
            }

            // assign the BDIs
            if (integerPartString == "0") {
                num.integerPart = BigDecimalInt(0);
            } else {
                num.integerPart = BigDecimalInt(integerPartString);
            }
            num.decimalPart = BigDecimalInt(decimalPartString);

            // assign the real sign
            num.realSign = num.integerPart.sign();

            validBigReal = true;

        }

    }

    return in;

}

// Youssef
void printDashes() {
    cout << string(20, '-') << endl;
}

string parseSign(int sign) {
    if (!sign) {
        return "-";
    }
    return "+";
}

// End of the file