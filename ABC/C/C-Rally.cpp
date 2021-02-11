#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    
    long long ans = INT64_MAX;
    for (int i = 0; i < 100; ++i) {
        long long sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += (v[j] - i) * (v[j] - i);
        }
        if (ans > sum) {
            ans = sum;
        }
    }

    cout << ans << endl;
    return 0;
}