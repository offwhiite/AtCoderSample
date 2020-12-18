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
    vector < long long > v(N, 0);
    for (int i = 0; i < N; ++i) cin >> v[i]; 
    vector < vector<long long> > dp(N+1, vector<long long>(N*100+1,0));
    dp[0][0] = 1;
    // i番目の品物を選んだ時、その重量にたいして、最も価値が高くなるのは
    // iを入れた場合の残りの重量におけるi-1番目の最も価値が高い状態のもの
    int count = 0;
    for (int i = 0; i < N; ++i) {
        // valueは残りの積載量を表す
        for (int value = 0; value <= N*100; ++value) {
            // もし入るのであればdpマップに保存する。
            if (dp[i][value] == 1) {
                dp[i+1][value+v[i]] = 1;
            }
            dp[i+1][value] = max(dp[i+1][value], dp[i][value]);
        }
    }

    for (int value = 0; value <= N*100; ++value) {
        // もし入るのであればdpマップに保存する。
        if (dp[N][value] == 1) count++;
    }
    cout  << count << endl; 
    return 0;
}