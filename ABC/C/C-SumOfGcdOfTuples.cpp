#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main() {
    int K;
    cin >> K;

    long long ans = 0;
    for(int a = 1; a <= K; ++a) {
        for (int b = 1; b <= K; ++b) {
            for (int c = 1; c <= K; ++c) {
                ans += gcd(a, gcd(b,c));
            }
        }
    }
    
    cout  << ans << endl;
    return 0;
}