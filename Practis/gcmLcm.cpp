#include <iostream>
using namespace std;

/**
 * greatest common divisor(最大公約数)をユークリッドの互除法を利用して取得する
 * - aとbの最大公約数はa%bの最大公約数と等しい
 */
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

/**
 * lowest common multiple(最小公倍数)を素因数分解に出てくる素数の指数が最大のものを掛け合わせる
 * - a,bの最小公倍数は、a,bの最大公約数で、a*bを割れば求められる
 */
int lcm(int x, int y) { return x / gcd(x, y) * y; }

int main() {
  int n, a, b;
  cin >> n >> a;

  /**
   * 複数の値からGCDを取得する
   * - a,b,cが存在するとき、aとbの最大公約数dとした時、dとcの最大公約数はa,b,cの最大公約数
   */
  for (int i = 1; i < n; i++) {
    cin >> b;
    a = gcd(a, b);
    cout << lcm(a,b) << endl;
  }
  cout << a << endl;
  
  return 0;
}