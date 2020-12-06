#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

long long gcd(long long  x, long long y) { return (x % y)? gcd(y, x % y): y; }
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
int main() {
    int N;
    cin >> N;
    vector <int> v(N-1,0);
    for (int i = 0; i <= N-2; ++i) v[i] = i + 2;
    long long now = 1;
    for (int i = 0; i <= N-2; ++i) {
        now = lcm(now, i+2);
    }
    now++;
    cout << now << endl;
    return 0;
}