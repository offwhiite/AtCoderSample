#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    string X;
    cin >> X;
    for (int i = 0; i < X.size(); ++i) {
        if (X[i] == '.') {
            cout << endl;
            return 0;
        }
        cout << X[i];
    }
    return 0;
}