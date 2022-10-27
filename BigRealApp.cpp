#include "BigRealFunctions.cpp"

int main() {

//    cout << BigDecimalInt("0009") + BigDecimalInt(21); // 30

// BigReal testcases here

    cout << BigReal(+055.000125) << endl; // 55.000125
    cout << BigReal(055.205) << endl; // 55.205000
    cout << BigReal(-075.030125) << endl; // -75.030125
    cout << BigReal("+055.000125") << endl; // 55.000125
    cout << BigReal("+055.0y00125") << endl; // Invalid
    cout << BigReal("-075.030125") << endl; // -75.030125
    cout << BigReal("+055.00125").sign() << endl; // 1
    cout << BigReal("055.00125").sign() << endl; // 0
    cout << BigReal("-055.00125").sign() << endl; // -1

    BigDecimalInt bi1 = BigDecimalInt("-0235");
    cout << BigReal(bi1) << endl; // -235.0
    BigDecimalInt bi2 = BigDecimalInt("235");
    cout << BigReal(bi1).size() << endl; // 6
    cout << BigReal(bi2).size() << endl; // 5

    return 0;
}
