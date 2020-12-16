#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <set>
using namespace std;

int main() {
    long long N;
    cin >> N;

    set<long long> v;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            v.insert(i);
            v.insert(N/i);
        }
    }

    for (long d: v) cout << d << endl;
    return 0;
}