#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N, A, B;
    cin >> N >> A >> B;

    long long sum = A + B;

    long long c = N / sum;
    long long r = N % sum;

    long long ans = c * A + min (r, A);

    cout  << ans << endl;
    return 0;
}