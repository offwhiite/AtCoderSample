#include <iostream>
using namespace std;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long N, M;
    cin >> N >> M;
    long long ans = modpow(10, N, M*M);
    long long a = ans / M;
    cout << a << endl;
    cout << ans / M % M << endl;
    return 0;
}