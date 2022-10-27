#ifndef BIGDECIMALINT_A1_T1_BIGDECIMALINTHEADER_H
#define BIGDECIMALINT_A1_T1_BIGDECIMALINTHEADER_H

#endif //BIGDECIMALINT_A1_T1_BIGDECIMALINTHEADER_H

#include <iostream>
#include "regex"

using namespace std;

// Prototypes, Constants and Classes

class BigDecimalInt {
private:
    string decimalStr;
    int decimalInt;
    int decimalSign;

public:
    inline BigDecimalInt(string decStr); // Initializes from string & rejects bad input
    inline BigDecimalInt(int decInt); // Initialize from integer

    inline BigDecimalInt operator+(BigDecimalInt anotherDec); // member fn
    inline BigDecimalInt operator-(BigDecimalInt anotherDec); // member fn
    inline bool operator<(BigDecimalInt anotherDec); // member fn
    inline bool operator>(BigDecimalInt anotherDec); // member fn
    inline bool operator==(BigDecimalInt anotherDec); // member fn
    inline BigDecimalInt operator=(BigDecimalInt anotherDec); // member fn

    inline int size(); // member fn
    inline int sign(); // member fn

    inline friend ostream &operator<<(ostream &out, BigDecimalInt b);

    inline string getDecimalStr(); // encapsulation
    inline void setDecimalStr(string decStr); // encapsulation

    inline BigDecimalInt();

};
