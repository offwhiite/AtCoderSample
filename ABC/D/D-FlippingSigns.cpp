#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <long long> v(N,0);
    bool isOdd = false;
    long long sum = 0;
    long long m = INT64_MAX;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        if (v[i] <= 0) {
            if(isOdd) isOdd = false;
            else isOdd = true;
        }
        sum += abs(v[i]);
        m = min(m, abs(v[i]) * 2);
    }

    if (isOdd) sum -= m;
    
    cout << sum << endl;
    return 0;
}