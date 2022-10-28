#include "BigRealFunctions.cpp"

int main() {

//    cout << BigDecimalInt("0009") + BigDecimalInt(21); // 30

//    BigReal testcases here

    cout << BigReal(+055.000125) << endl; // 55.000125
    cout << BigReal(055.205) << endl; // 55.205000
    cout << BigReal(-075.030125) << endl; // -75.030125
    cout << BigReal("+055.000125") << endl; // 55.000125
    cout << BigReal("+055.0y00125") << endl; // Invalid
    cout << BigReal("-075.030125") << endl; // -75.030125
    cout << BigReal("+055.00125").sign() << endl; // 1
    cout << BigReal("055.00125").sign() << endl; // 0
    cout << BigReal("-055.00125").sign() << endl; // -1
    printDashes();

    BigDecimalInt bi1 = BigDecimalInt("-0235");
    cout << BigReal(bi1) << endl; // -235.0
    BigDecimalInt bi2 = BigDecimalInt("235");
    cout << BigReal(bi1).size() << endl; // 6
    cout << BigReal(bi2).size() << endl; // 5
    printDashes();

    BigReal br1 = BigReal("-235");
    BigReal br2 = BigReal("235.0");
    BigReal br3 = BigReal(br1);
    BigReal br4 = BigReal(br2);
    cout << br3 << endl; // -235.0
    cout << br4 << endl; // 235.0
    printDashes();

    BigReal br5 = BigReal("-4522.0");
    BigReal br6 = BigReal("5612");
    BigReal br7 = br5;
    BigReal br8 = br6;
    cout << br7.sign() << endl; // -1
    cout << br8 << endl; // 5612.0
    printDashes();

    BigReal br9(BigReal("-50"));
    BigReal br10(BigReal("300"));
    cout << br9.sign() << endl; // -1
    cout << br10 << endl; // 300.0
    printDashes();

    BigReal br11 = BigReal(BigReal("+1440"));
    BigReal br12 = BigReal(BigReal("4044"));
    cout << br11.sign() << endl; // 1
    cout << br12 << endl; // 4044.0
    printDashes();

    BigReal br13("1000.2556");
    BigReal br14("1000.2556");
    BigReal br15("500.2556");
    if (br13 == br14) { // true
        cout << "True!\n";
    } else {
        cout << "False!\n";
    }
    if (br13 == br15) { // false
        cout << "True!\n";
    } else {
        cout << "False!\n";
    }
    printDashes();


    BigReal br16("5000.344");
    BigReal br17("5000.244");
    BigReal br18("-1000.344");
    BigReal br19("-5000.344");
    if (br16 > br17) {   // true
        cout << "True!\n";
    } else {
        cout << "False!\n";
    }

    if (br16 > br18) {   //true
        cout << "True!\n";
    } else {
        cout << "False!\n";
    }

    if (br17 < br16) {   //true
        cout << "True!\n";
    } else {
        cout << "False!\n";
    }

    if (br18 > br19) {   //true
        cout << "True!\n";
    } else {
        cout << "False!\n";
    }

    if (br19 < br18) {   //true
        cout << "True!\n";
    } else {
        cout << "False!\n";
    }
    printDashes();

    cout << (BigDecimalInt("6") > BigDecimalInt("10")) << endl;
    cout << (BigDecimalInt("6") < BigDecimalInt("10")) << endl;
    cout << (BigDecimalInt("-6") < BigDecimalInt("10")) << endl;
    printDashes();

    BigReal br20(BigReal("0.1"));
    cout << br20.sign() << endl;
    cout << br20 << endl;
    printDashes();

    return 0;
}

// End of the file