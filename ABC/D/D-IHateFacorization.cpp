#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * マイナスでもプラスでも結果変わらない？
 */
int main() {
    long long X;
    cin >> X;
    long long calcA = 0, calcB = 0;
    for (long long a = 0; calcA < 1000000000000000; ++a) {
        calcA = a * a * a * a * a;
        calcB = 0;
        for (long long b = 0; calcB < 1000000000000000; ++b) {
            calcB = b * b * b * b * b;
            if (calcA - calcB == X) {
                cout << a << " " << b << endl;
                return 0;
            } else if (calcA + calcB == X) {
                cout << a << " " << -b << endl;
                return 0;
            }
        }
    }

    return 0;
}