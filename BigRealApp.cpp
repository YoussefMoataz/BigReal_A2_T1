#include "BigRealFunctions.cpp"

int main() {

//    cout << BigDecimalInt("0009") + BigDecimalInt(21); // 30

// BigReal testcases here

    BigReal("123.456");
    BigReal("0525.25");
    BigReal("+56.0025");

    cout << BigReal("+055.000125") << endl;
    cout << BigReal("+055.0y00125") << endl;
    cout << BigReal("-075.030125") << endl;
    cout << BigReal("+055.00125").sign() << endl;
    cout << BigReal("055.00125").sign() << endl;
    cout << BigReal("-055.00125").sign() << endl;

    return 0;
}
