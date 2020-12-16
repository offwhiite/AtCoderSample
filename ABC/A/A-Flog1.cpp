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
    vector <int> dp(N,0);
    dp[0] = 0;
    dp[1] = abs(v[1]-v[0]);
    for (int i = 2; i < N; ++i) {
        int step1 = dp[i-1] + abs(v[i-1] - v[i]); // 一つ前のノードから飛ぶ
        int step2 = dp[i-2] + abs(v[i-2] - v[i]); // 二つ前のノードから飛ぶ
        if (step1 <= step2) dp[i] = step1;
        else dp[i] = step2;
    }
    cout  << dp[N-1] << endl;
    return 0;
}