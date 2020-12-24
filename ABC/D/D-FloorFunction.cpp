#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long A,B,N;
    cin >> A >> B >> N;
    long long x = min(N, B-1);
    double div = (double)x/B;
    long long ans = A * div;
    cout << ans << endl;
    return 0;
}