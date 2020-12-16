#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int S;
    cin >> S;
    vector <int> dp(S+1,0);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;
    for (int i = 3; i <= S; ++i) {
        for (int j = 0; j <= (i - 3); ++j) {
            dp[i] += dp[j];
            dp[i] %= 1000000000 + 7;
        }
    }
    
    cout  << dp[S] << endl;
    return 0;
}