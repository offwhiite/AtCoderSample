#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;


/**
 * greatest common divisor(最大公約数)をユークリッドの互除法を利用して取得する
 * - aとbの最大公約数はa%bの最大公約数と等しい
 */
long long gcd(long long x, long long y) { return (x % y)? gcd(y, x % y): y; }

map<long long, long long> calcDivisorNum(long long N) {
    if (N == 0 || N==1) return map <long long, long long>();

    // 約数の数を計算する:素数の数を数える
    int tmp=N;
    map <long long, long long> m;
    for (long long p = 2; p * p <= N; ++p) {
        while (N % p == 0) {m[p]++; N /= p; }
    }
    if (N != 1) m[N]++;
    return m;
}

int main() {
    long long A,B;
    cin >> A >> B;

    // A,Bの最大公約数をGとしたとき、Gの約数を列挙するとA,Bの公約数の列挙となる
    long long G = gcd(A,B);
    map <long long, long long> m = calcDivisorNum(G);
    cout  << m.size() + 1 << endl;
    return 0;
}