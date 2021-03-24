#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N; cin >> N;
    const long long one = 1000;
    const long long two = 1000000;
    const long long three = 1000000000;
    const long long four = 1000000000000;
    const long long five = 1000000000000000;
    long long ans = 0;
    ans += N%five%four%three%two-one;
    ans += N%five%four%three-two-ans;
    // ans += N%five%four%three%two%one;
    // N-=N%five%four%three%two;
    // ans += N%five%four%three%two * 2;
    // N-=N%five%four%three;
    // ans += N%five%four%three * 3; 
    // N-=N%five%four;
    // ans++;
    // ans += N%five%four * 4;
    // N-=N%five;
    // ans++;
    // ans += N%five * 5;
    // ans++;
    cout << ans << endl;
    return 0;
}