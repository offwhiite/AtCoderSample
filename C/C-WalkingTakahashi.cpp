#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long X,K,D;
    cin >> X >> K >> D;
    X = abs(X);

    long long ans = 0;
    if (abs(X) >= abs(K * D)) {
      ans = X - K * D;
    } else {
        long long count = abs(X / D); // 最小何回で最小値にたどり着くか

        // 一応＋1回分探索する
        if (count < K && abs(abs(X) - ((count + 1) * D)) < abs(abs(X) - (count * D))) {
            count++;
        }

        ans = X - count * D; 

        // 最小回数に到達した後、何回動く必要があるか計算する
        // 偶数の場合は行って戻れば良いので最小回数で良い
        // 奇数の場合は戻ってこれないので+1回する必要がある
        if (count < K && (K - count) % 2 != 0) {
            ans = ans - D;
        } 
    }
    cout  << abs(ans) << endl;
    return 0;
}