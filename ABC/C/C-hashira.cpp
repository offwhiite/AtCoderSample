#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    vector <int> dp(N+1,0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(v[0] - v[1]);

    for (int i = 2; i < N; ++i) {
        int cost1 = abs(v[i] - v[i-1]) + dp[i]; // 一つ前の柱から飛んだ場合のコスト
        int cost2 = abs(v[i] - v[i-2]) + dp[i-1]; // 二つ前の柱から飛んだ場合のコスト 
        if (cost1 > cost2) dp[i+1] = cost2;
        else dp[i+1] = cost1;
    }
    cout  << dp[N] << endl;
    return 0;
}