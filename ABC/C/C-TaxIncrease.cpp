#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int A,B;
    cin >> A >> B;
    vector <int> v(1010,0);
    for (int i = 1; i < 1010; ++i) {
        int aTax = i*0.08;
        int bTax = i*0.1;
        if (aTax == A && bTax == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}