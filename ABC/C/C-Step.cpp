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
    
    long long ans = 0;
    for (int i = 0; i < N-1; ++i) {
        if (v[i] > v[i+1]) {
            long long d = v[i] - v[i+1];
            v[i+1] += d;
            ans += d;
        }
    }
    cout  << ans << endl;
    return 0;
}