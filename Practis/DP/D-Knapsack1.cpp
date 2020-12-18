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
    int N, W;
    cin >> N >> W;
    vector < vector<long long> > v(N, vector<long long>(2,0));
    for (int i = 0; i < N; ++i) cin >> v[i][0] >> v[i][1]; 
    vector < vector<long long> > dp(N+1, vector<long long>(W+1,0));

    // i番目の品物を選んだ時、その重量にたいして、最も価値が高くなるのは
    // iを入れた場合の残りの重量におけるi-1番目の最も価値が高い状態のもの
    for (int i = 0; i < N; ++i) {
        // weightは残りの積載量を表す
        for (int weight = 0; weight <= W; ++weight) {
            // もし入るのであればdpマップに保存する。
            if (weight-v[i][0]>=0) chmax(dp[i+1][weight], dp[i][weight-v[i][0]] + v[i][1]);
            chmax(dp[i+1][weight], dp[i][weight]);
        }
    }
    cout  << dp[N][W] << endl; 
    return 0;
}