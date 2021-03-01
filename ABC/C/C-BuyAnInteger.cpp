#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
using ll = int64_t;
// 桁数
ll calc(ll A, ll B, ll mid) {
    ll digit=0;
    ll N = mid;
    while(N != 0) {
        digit++;
        N/=10;
    }
    return A * mid + B * digit;
}


int main() {
    ll A,B,X; cin >> A >> B >> X;
    ll right = X;
    ll left = 0;
    while(right-left > 1) {
        ll mid = (left + right) / 2;
        if (calc(A,B,mid) > X) right = mid;
        else left = mid;
    }
    cout << left << endl;
}