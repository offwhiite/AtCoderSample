#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    string S;
    cin >> S;
    if (S == "AAA" || S == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}