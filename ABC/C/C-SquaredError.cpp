#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N; cin >> N;
    vector <long long> v(N+1,0);
    vector <long long> sum(N+1,0);
    vector <long long> sum2(N+1,0);
    for (int i = 0; i < N; ++i) {
        long long a; cin >> a;
        v[i+1] = a;
        sum[i+1] = a + sum[i];
        sum2[i+1] = (a * a) + sum2[i];
    }
    
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        long long d = v[i];
        // 何個の和が必要か
        long long count = N - i;
        // 二乗系の計算
        long long d2 = sum2[N] - sum2[i];
        // 一次式の計算
        long long d1 = -2 * d * (sum[N] - sum[i]);
        // 定数の計算
        long long c = (d * d) * count;
        // 和
        ans += d2 + d1 + c;
    }
    cout << ans << endl;
    return 0;
}