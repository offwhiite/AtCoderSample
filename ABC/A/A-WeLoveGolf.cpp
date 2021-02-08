#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int K, A, B;
    cin >> K >> A >> B;
    for (int i = K; i <= B; i += K) {
        if (A <= i && B >= i) {
            cout << "OK" << endl;
            return 0;
        }
    }
    
    cout << "NG" << endl;
    return 0;
}