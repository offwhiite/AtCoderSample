#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long A;
    double B;
    cin >> A >> B;
    long long tmpB = B * (long long)100 +0.001;
    long long ans = A * tmpB / 100;
    cout  << ans << endl;
    return 0;
}