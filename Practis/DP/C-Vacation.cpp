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
    int N;
    cin >> N;
    vector < vector<long long> > v(N, vector<long long>(3,0));
    for (int i = 0; i < N; ++i) cin >> v[i][0] >> v[i][1] >> v[i][2]; 
    vector < vector<long long> > dp(N+1, vector<long long>(3,0));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;// 一段目

    for (int i = 0; i < N; ++i) {
        chmax(dp[i+1][0], dp[i][1] + v[i][0]);
        chmax(dp[i+1][0], dp[i][2] + v[i][0]);
        chmax(dp[i+1][1], dp[i][0] + v[i][1]);
        chmax(dp[i+1][1], dp[i][2] + v[i][1]);
        chmax(dp[i+1][2], dp[i][0] + v[i][2]);
        chmax(dp[i+1][2], dp[i][1] + v[i][2]);
    }
    cout  << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl; 
    return 0;
}