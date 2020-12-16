#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main() {
    int N, K;
    cin >> N >> K;
    vector <long long> v(N+1000,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    vector <long long> dp(N+1000, INF);
    dp[0] = 0; // 一段目
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= K; ++j) {
            // 一段目からいける範囲の物をdpにメモしていく
            // 次は2段目からいける範囲の物で小さいものをメモしていくのを繰り返す
            chmin(dp[i + j], dp[i] + abs(v[i+j] - v[i]));
        }
    }
    cout  << dp[N-1] << endl; // N段目はN-1段目
    return 0;
}