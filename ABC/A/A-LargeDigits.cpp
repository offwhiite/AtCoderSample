#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    string A,B;
    cin >> A >> B;
    int aSum = 0;
    int bSum = 0;
    for (int i = 0; i < A.size(); ++i) {
        aSum += A[i] - '0';
        bSum += B[i] - '0';
    }
    if (aSum >= bSum) cout << aSum;
    else cout << bSum;
    cout << endl;

    return 0;
}