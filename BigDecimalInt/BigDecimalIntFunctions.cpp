#include "BigDecimalIntHeader.h"

// Defining functions, class methods

// 'a'
// Youssef
BigDecimalInt::BigDecimalInt(string decStr) {

    regex filter("^[+-]?[0-9]+");
    if (regex_match(decStr, filter)) {

        int i = 0;
        if (decStr[0] == '+' || decStr[0] == '-') {

            decimalStr += decStr[0];
            i = 1;

        }

        for (; i < decStr.length(); ++i) {

            if (decStr[i] != '0') {
                break;
            }

        }

        for (; i < decStr.length(); ++i) {

            decimalStr += decStr[i];

        }


    } else {
        cout << "Invalid Input";
    }


}

// 'b'
// Hassan
BigDecimalInt::BigDecimalInt(int decInt) {

    decimalInt = decInt;
    decimalStr = to_string(decInt);

}

// 'c'
// Hassan
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    int sign1 = this->sign();
    int sign2 = anotherDec.sign();
    int rmndr = 0;
    int intNum1, intNum2, intresult, addedzero;
    string StrNum1 = this->decimalStr, StrNum2 = anotherDec.decimalStr, result = "", chtostr, strresult;
    if (sign1 < 0 || sign1 > 0) {
        StrNum1[0] = '0';
    }
    if (sign2 < 0 || sign2 > 0) {
        StrNum2[0] = '0';
    }
    if (StrNum1.size() != StrNum2.size())
        if (StrNum1.size() > StrNum2.size()) {
            int addedzero = StrNum1.size() - StrNum2.size();
            for (int i = 0; i < addedzero; i++) {
                StrNum2 = "0" + StrNum2;
            }
        } else {
            int addedzero = StrNum2.size() - StrNum1.size();
            for (int i = 0; i < addedzero; i++) {
                StrNum1 = "0" + StrNum1;
            }
        }
    //first case
    if (sign1 >= 0 && sign2 >= 0) {
        for (int i = StrNum1.size() - 1; i > -1; i--) {
            chtostr = StrNum1[i];
            intNum1 = stoi(chtostr);
            intNum1 += rmndr;
            if (rmndr > 0) {
                rmndr--;
            }
            chtostr = StrNum2[i];
            intNum2 = stoi(chtostr);
            intresult = intNum1 + intNum2;
            if (intresult >= 10 && i != 0) {
                intresult -= 10;
                rmndr++;
            }
            strresult = to_string(intresult);
            result = strresult + result;
        }
        return result;

    }
    //second case
    if (sign1 < 0 && sign2 < 0) {
        for (int i = StrNum1.size() - 1; i > -1; i--) {
            chtostr = StrNum1[i];
            intNum1 = stoi(chtostr);
            intNum1 += rmndr;
            if (rmndr > 0) {
                rmndr--;
            }
            chtostr = StrNum2[i];
            intNum2 = stoi(chtostr);
            intresult = intNum1 + intNum2;
            if (intresult >= 10 && i != 0) {
                intresult -= 10;
                rmndr++;
            }
            strresult = to_string(intresult);
            result = strresult + result;
        }
        result = "-" + result;
        return result;
    }
    //third case
    if (sign1 < 0 or sign2 < 0) {
        if (sign1 < sign2) {
            swap(StrNum1, StrNum2);
        }
        if (StrNum2 > StrNum1) {
            swap(StrNum1, StrNum2);
            for (int i = StrNum1.size() - 1; i > -1; i--) {
                chtostr = StrNum1[i];
                intNum1 = stoi(chtostr);
                chtostr = StrNum2[i];
                intNum2 = stoi(chtostr);
                if (rmndr > 0) {
                    intNum1 -= rmndr;
                    rmndr--;
                }
                if (intNum1 < intNum2) {
                    intresult = (intNum1 + 10) - intNum2;
                    rmndr++;
                } else {
                    intresult = intNum1 - intNum2;
                }
                strresult = to_string(intresult);
                result = strresult + result;
            }
            // result="-"+result;
            return result;
        }
        for (int i = StrNum1.size() - 1; i > -1; i--) {
            chtostr = StrNum1[i];
            intNum1 = stoi(chtostr);
            chtostr = StrNum2[i];
            intNum2 = stoi(chtostr);
            if (rmndr > 0) {
                intNum1 -= rmndr;
                rmndr--;
            }
            if (intNum1 < intNum2) {
                intresult = (intNum1 + 10) - intNum2;
                rmndr++;
            } else {
                intresult = intNum1 - intNum2;
            }
            strresult = to_string(intresult);
            result = strresult + result;
        }
        return result;

    }

    return anotherDec;
}

// 'd'
// Hassan
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {
    int sign1 = this->sign();
    int sign2 = anotherDec.sign();
    int rmndr = 0;
    int intNum1, intNum2, intresult, addedzero;
    string StrNum1 = this->decimalStr, StrNum2 = anotherDec.decimalStr, result = "", chtostr, strresult;
    if (sign1 < 0 || sign1 > 0) {
        StrNum1[0] = '0';
    }
    if (sign2 < 0 || sign2 > 0) {
        StrNum2[0] = '0';
    }
    if (StrNum1.size() != StrNum2.size())
        if (StrNum1.size() > StrNum2.size()) {
            int addedzero = StrNum1.size() - StrNum2.size();
            for (int i = 0; i < addedzero; i++) {
                StrNum2 = "0" + StrNum2;
            }
        } else {
            int addedzero = StrNum2.size() - StrNum1.size();
            for (int i = 0; i < addedzero; i++) {
                StrNum1 = "0" + StrNum1;
            }
        }
    //first case
    if ((sign1 >= 0 && sign2 >= 0) || (sign1 < 0 && sign2 < 0)) {
        if (StrNum2 > StrNum1) {
            swap(StrNum1, StrNum2);
            for (int i = StrNum1.size() - 1; i > -1; i--) {
                chtostr = StrNum1[i];
                intNum1 = stoi(chtostr);
                chtostr = StrNum2[i];
                intNum2 = stoi(chtostr);
                if (rmndr > 0) {
                    intNum1 -= rmndr;
                    rmndr--;
                }
                if (intNum1 < intNum2) {
                    intresult = (intNum1 + 10) - intNum2;
                    rmndr++;
                } else {
                    intresult = intNum1 - intNum2;
                }
                strresult = to_string(intresult);
                result = strresult + result;
            }
            result = "-" + result;
            return result;
        }
        for (int i = StrNum1.size() - 1; i > -1; i--) {
            chtostr = StrNum1[i];
            intNum1 = stoi(chtostr);
            chtostr = StrNum2[i];
            intNum2 = stoi(chtostr);
            if (rmndr > 0) {
                intNum1 -= rmndr;
                rmndr--;
            }
            if (intNum1 < intNum2) {
                intresult = (intNum1 + 10) - intNum2;
                rmndr++;
            } else {
                intresult = intNum1 - intNum2;
            }
            strresult = to_string(intresult);
            result = strresult + result;
        }
        if (sign1 < 0) {
            result = "-" + result;
        }
        return result;
    }
        //case 2
    else {
        if (sign2 < 0 || sign1 < 0) {
            for (int i = StrNum1.size() - 1; i > -1; i--) {
                chtostr = StrNum1[i];
                intNum1 = stoi(chtostr);
                intNum1 += rmndr;
                if (rmndr > 0) {
                    rmndr--;
                }
                chtostr = StrNum2[i];
                intNum2 = stoi(chtostr);
                intresult = intNum1 + intNum2;
                if (intresult >= 10 && i != 0) {
                    intresult -= 10;
                    rmndr++;
                }
                strresult = to_string(intresult);
                result = strresult + result;
            }
            if (sign1 < 0) {
                result = "-" + result;
            }
            return result;
        }
    }
    return anotherDec;
}

// 'e'
// Seif
bool BigDecimalInt::operator<(BigDecimalInt anotherDec) {
    string str1 = "";
    string str2 = "";

    if (this->sign() == -1 && anotherDec.sign() != -1) {
        return true;
    }

    if (this->sign() != -1 && anotherDec.sign() == -1) {
        return false;
    }

    if (this->sign() == 1 || this->sign() == -1) {
        for (int i = 1; i < this->decimalStr.length(); i++) {
            str1 += this->decimalStr[i];
        }
    }

    if (anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for (int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 += anotherDec.decimalStr[i];
        }
    }


    if (anotherDec.sign() != -1) {
        if (str1.length() > str2.length()) {
            return false;
        } else if (str1.length() < str2.length()) {
            return true;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return false;
                } else if (stoi(num1) < stoi(num2)) {
                    return true;
                } else {
                    continue;
                }
            }
            return false;
        }
    } else if (anotherDec.sign() == -1) {
        if (str1.length() > str2.length()) {
            return true;
        } else if (str1.length() < str2.length()) {
            return false;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return true;
                } else if (stoi(num1) < stoi(num2)) {
                    return false;
                } else {
                    continue;
                }
            }
            return false;
        }
    }
}

// 'f'
// Seif
bool BigDecimalInt::operator>(BigDecimalInt anotherDec) {

    string str1 = "";
    string str2 = "";

    if (this->sign() == -1 && anotherDec.sign() != -1) {
        return false;
    }

    if (this->sign() != -1 && anotherDec.sign() == -1) {
        return true;
    }

    if (this->sign() == 1 || this->sign() == -1) {
        for (int i = 1; i < this->decimalStr.length(); i++) {
            str1 += this->decimalStr[i];
        }
    } else {
        str1 = this->decimalStr;
    }


    if (anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for (int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 += anotherDec.decimalStr[i];
        }
    } else {
        str2 = anotherDec.decimalStr;
    }


    if (anotherDec.sign() != -1) {
        if (str1.length() > str2.length()) {
            return true;
        } else if (str1.length() < str2.length()) {
            return false;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return true;
                } else if (stoi(num1) < stoi(num2)) {
                    return false;
                } else {
                    continue;
                }
            }
            return false;
        }
    } else if (anotherDec.sign() == -1) {
        if (str1.length() > str2.length()) {
            return false;
        } else if (str1.length() < str2.length()) {
            return true;
        } else {
            string num1;
            string num2;
            for (int i = 0; i < str1.length(); i++) {
                num1 = str1[i];
                num2 = str2[i];
                if (stoi(num1) > stoi(num2)) {
                    return false;
                } else if (stoi(num1) < stoi(num2)) {
                    return true;
                } else {
                    continue;
                }
            }
            return false;
        }
    }
}

// 'g'
// Seif
bool BigDecimalInt::operator==(BigDecimalInt anotherDec) {

    string str1 = "";
    string str2 = "";

    if (this->sign() == -1 && anotherDec.sign() != -1) {
        return false;
    }

    if (this->sign() != -1 && anotherDec.sign() == -1) {
        cout << "Str1 = " << str1 << endl;
        cout << "Str2 = " << str2 << endl;
        return false;
    }

    if (this->sign() == 1 || this->sign() == -1) {
        for (int i = 1; i < this->decimalStr.length(); i++) {
            str1 += this->decimalStr[i];
        }
    } else {
        str1 = this->decimalStr;
    }


    if (anotherDec.sign() == 1 || anotherDec.sign() == -1) {
        for (int i = 1; i < anotherDec.decimalStr.length(); i++) {
            str2 += anotherDec.decimalStr[i];
        }
    } else {
        str2 = anotherDec.decimalStr;
    }


    if (str1.length() != str1.length()) {
        return false;
    } else {
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                return false;
            } else {
                continue;
            }
        }
        return true;
    }
}

// 'h'
// Youssef
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec) {

    decimalStr = anotherDec.decimalStr;
    decimalInt = anotherDec.decimalInt;
    decimalSign = anotherDec.decimalSign;

    return *this;
}

// 'i'
// Youssef
int BigDecimalInt::size() {

    return this->decimalStr.length();

}

// 'j'
// Youssef
int BigDecimalInt::sign() {

    if (decimalStr[0] == '+') {

        decimalSign = 1;

    } else if (isdigit(decimalStr[0])) {

        decimalSign = 0;

    } else {

        decimalSign = -1;

    }

    return decimalSign;
}

// 'k'
// Youssef
ostream &operator<<(ostream &out, BigDecimalInt b) {

    // handles no string after plus, minus = 0
    if (b.size() == 0){
        out << "0";
        return out;
    }

    // handles negative sign only after plus, minus = 0
    if (b.size() == 1 && b.decimalStr[0] == '-'){
        out << "0";
        return out;
    }

    if (b.sign() == 1) {

        for (int i = 1; i < b.size(); ++i) {

            out << b.decimalStr[i];

        }

    } else {

        out << b.decimalStr;

    }

    return out;
}

// Youssef
string BigDecimalInt::getDecimalStr() {

    return decimalStr;

}

// Youssef
void BigDecimalInt::setDecimalStr(string decStr) {

    decimalStr = decStr;

}

// Youssef
BigDecimalInt::BigDecimalInt() {}

// End of file