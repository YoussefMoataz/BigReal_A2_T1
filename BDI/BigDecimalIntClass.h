// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 1
// Program Name: BigDecimalInt
// Last Modification Date: 13/10/2022
// Author1 and ID and Group: Basmala Mohamed Sayed Gad  ID: 20210090 (a, b, c)
// Author2 and ID and Group: Aya Ali Hassan  ID: 20210083 (d, e)
// Author3 and ID and Group: Mohamed Ashraf Fahim  ID: 20210329 (f, i, j , k)
/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited decimal integer values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */

#ifndef BIGDECIMALINT_BIGDECIMALINTCLASS_H
#define BIGDECIMALINT_BIGDECIMALINTCLASS_H

#include <iostream>
#include <deque>
#include <regex>

using namespace std;

class BigDecimalInt{
private:
    string number;
    char signNumber;
    inline bool checkValidInput(string input);

public:
    inline bool operator < (const BigDecimalInt& anotherDec);
    inline bool operator > (const BigDecimalInt& anotherDec);
    inline bool operator == (const BigDecimalInt anotherDec);
    inline BigDecimalInt& operator = (BigDecimalInt anotherDec);
    inline BigDecimalInt operator + (BigDecimalInt number2);
    inline BigDecimalInt operator - (BigDecimalInt anotherDec);
    inline friend ostream &operator << (ostream &out, BigDecimalInt num);
    inline int size();
    inline int sign();
    inline void setNumber(string num);
    inline string getNumber(){
        return number;
    }
    inline BigDecimalInt(){}
    inline BigDecimalInt(string num)
    {
        setNumber(num);
    }

};

inline string subtraction(string num1,string num2);
inline string addition(string num1,string num2);

#endif //BIGDECIMALINT_BIGDECIMALINTCLASS_H
