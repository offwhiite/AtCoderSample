#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
/**
 * greatest common divisor(最大公約数)をユークリッドの互除法を利用して取得する
 * - aとbの最大公約数はa%bの最大公約数と等しい
 */
long long gcd(long long x, long long y) { return (x % y)? gcd(y, x % y): y; }
/**
 * lowest common multiple(最小公倍数)を素因数分解に出てくる素数の指数が最大のものを掛け合わせる
 * - a,bの最小公倍数は、a,bの最大公約数で、a*bを割れば求められる
 */
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }

int main() {
    long long A,B,C,D;
    cin >> A >> B >> C >> D;
    long long dAC = A/C;
    if (A%C==0) dAC--;
    long long dBC = B/C;
    long long dAD = A/D;
    if (A%D==0) dAD--;
    long long dBD = B/D;

    long long LCM = lcm(C,D);
    long long dALCM = A/LCM;
    if (A%LCM==0) dALCM--;
    long long dBLCM = B/LCM;
    
    cout << (B - A + 1) - ((dBC - dAC) + (dBD - dAD) - (dBLCM - dALCM)) << endl;
    return 0;
}