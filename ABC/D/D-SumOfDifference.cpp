#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <long long> v(N,0);
    vector <long long> sum(N+1, 0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < N; ++i) sum[i+1] = sum[i] + v[N-1-i];
    long long ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        long long calc = N-(i + 1);
        ans += sum[calc] - v[i] * calc;
    } 
    cout  << ans << endl;
    return 0;
}