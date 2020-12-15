#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N, S;
    const long long m = 1000000007;
    cin >> N >> S;
    vector <bool> v(N+1,true);
    for (int i = 0; i < S; ++i) {
        int tmp;
        cin >> tmp;
        v[tmp] = false;
    }
    
    vector <long long> dp(N+2,0);
    if (v[1] == false && v[2] == false) {
        cout << 0 << endl;
        return 0;
    } 
    dp[0] = 1;
    if (v[1] == false) {
            dp[1] = 0;
    } else {
        dp[1] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        if (!v[i]) {
            continue;
        } 
        // 壊れた階段かどうか判定して足す
        if (v[i-2]) dp[i] = (dp[i] + dp[i-2]) % m;
        if (v[i-1]) dp[i] = (dp[i] + dp[i-1]) % m;
    }

    cout  << dp[N] << endl;
    return 0;
}