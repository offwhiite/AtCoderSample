#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * Ubiquity
 * - 
 */

long long calc(long long num, long long N, long long mod) {
    long long ans = 1;
    for (long long i = 0; i < N; ++i) ans = (ans * num) % mod;
    return ans;
}
int main() {
    long long N;
    cin >> N;

    long long mod = 1000000007;
    long long total = (calc(9,N,mod) + calc(9,N,mod)) % mod;
    long long result = total - calc(8,N,mod);
    result = result + mod; // 引き算のmodの時はちゃんとmodを足すこと
    result = result % mod;
    long long ans = calc(10, N, mod) - result; // 10^N - (9^N + 9^N - 8^N)
    ans = ans + mod;
    cout  << ans % mod << endl;
    return 0;
}