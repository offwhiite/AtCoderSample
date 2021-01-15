#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    if (A == B && B != C || B == C && A != C || A == C && B != C) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}