#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector <long> A(N,0);
    vector <long long> S(N+1,0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }

    long mod = 1;
    for (int i = 0; i < 9;++i) mod = mod * 10;
    mod += 7;
    long long ans = 0;
    for (int i = 0; i < N-1; ++i) {
        long long sum = (S[N] - S[i+1]) % mod;
        ans += (A[i] * sum) % mod;
    }
    cout << ans % mod << endl;
    return 0;
}