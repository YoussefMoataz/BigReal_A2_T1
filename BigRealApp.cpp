/*
FCAI - Programming 2 - 2022 - Assignment 2 - Task 1
Program Name:           Big Real
Program Description:    This program is presenting the new data type BigReal which uses a BigDecimalInt library
                        with some additions such as working with limitless non-int values, bigger than "long double"
Last Modification Date: November 2, 2022
Version:                v4.1.7
Authors:                Youssef Moataz, Hassan Magdy,   Mohamed Maged
ID:                     20210488,       20210126,       20210352
Group:                  A
Labs:                   S9-S10
Purpose:                Mastering OOP by making a new limitless data type (with decimal point)
*/

#include "BigRealFunctions.cpp"

int main() {

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

    cout << (BigDecimalInt("6") > BigDecimalInt("10")) << endl; // 0
    cout << (BigDecimalInt("6") < BigDecimalInt("10")) << endl; // 1
    cout << (BigDecimalInt("-6") < BigDecimalInt("10")) << endl; // 1
    printDashes();

    BigReal br20(BigReal("0.1"));
    cout << br20.sign() << endl; // 0
    cout << br20 << endl; // 0.1
    printDashes();

    BigReal br21 = BigReal("-1.1");
    //    cin >> br21;  // uncomment to get input
    cout << br21.sign() << endl;
    cout << br21 << endl;
    printDashes();

    BigReal br22 = BigReal("+1.1");
    //    cin >> br21;  // uncomment to get input
    cout << br22.sign() << endl;
    cout << br22 << endl;
    printDashes();

    BigReal br23("9.1");
    BigReal br24("10.901");
    cout << br23 + br24 << endl; // 20.001
    cout << br24 + br23 << endl; // 20.001
    printDashes();

    BigReal br25("9.1");
    BigReal br26("10.901");
    cout << (br25 - br26).sign() << endl; // -1
    cout << br25 - br26 << endl; // -1.801
    cout << (br26 - br25).sign() << endl; // 0
    cout << br26 - br25 << endl; // 1.801
    printDashes();

    BigReal br27("-9.1");
    BigReal br28("10.901");
    cout << (br27 - br28).sign() << endl; // -1
    cout << br27 - br28 << endl; // -20.001
    cout << (br28 - br27).sign() << endl; // 0
    cout << br28 - br27 << endl; // 20.001
    printDashes();

    BigReal br29("9.1");
    BigReal br30("-10.901");
    cout << (br29 + br30).sign() << endl; // -1
    cout << br29 + br30 << endl; // -1.801
    cout << (br30 + br29).sign() << endl; // -1
    cout << br30 + br29 << endl; // -1.801
    printDashes();

    cout << BigReal("0.0011") << endl; // 0.0011
    cout << BigReal("0.22") << endl; // 0.22
    printDashes();

    BigReal br31("-0.02");
    BigReal br32("0.01");
    cout << br31 + br32 << endl; // -0.01
    cout << (br31 + br32).size() << endl; // 3
    cout << (br31 + br32).sign() << endl; // 0
    printDashes();

    BigReal br33("0.1");
    BigReal br34("0.022");
    cout << br33 + br34 << endl; // 0.122
    printDashes();

    cout << BigReal("-50") << endl;
    printDashes();

    BigReal br35("-50.1");
    BigReal br36("-50.1");
    cout << br35 + br36 << endl; // -100
    printDashes();

    BigDecimalInt bi37("-50");
    BigDecimalInt bi38("-50");
    cout << bi37 + bi38 << endl; // -100.2
    printDashes();

    BigReal br39("0.1");
    BigReal br40("0.022");
    cout << br39 - br40 << endl; // 0.078
    printDashes();

    BigReal br41(".50");
    BigReal br42("-.300");
    cout << br41.sign() << endl; // 1
    cout << br41 << endl; // 0.50
    cout << br42 << endl; // -0.300
    printDashes();

    BigReal br43(".50");
    BigReal br44("-.300");
    cout << br44.sign() << endl; // 0
    cout << br41 + br39 << endl; // 0.60
    cout << br42 + br39 << endl; // -0.200
    printDashes();

    // Doctor's testcase
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << n3 << endl;
    n3 = n3 + BigReal (0.9);
    cout<< n3 << endl;
    printDashes();

    return 0;
}

// End of the file