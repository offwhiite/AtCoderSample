#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 考えたこと
 * - 連続区間の和ということで累積和をまず考える。
 * - 各区間の和は累積和の差で表せるので。
 * - ただ普通に全部の部分列を計算するとN * N/2となりタイムオーバーな気がする。
 * - ここからどうにか計算量を省きたい
 * - 例えば累積和をとってK+差分以上の値が出るところを二分探索で探す
 * - するとNlogNとなってギリ間に合うか...？
 * - 間に合った。Kがlonglongなのを忘れてて１WAはもったいない。。
 * - 尺取り法というものがあるらしいのでそちらもキャッチアップする
 */
int main() {
    long long N, K;
    cin >> N >> K;
    vector <long long> v(N+1,0); // 累積和
    for (int i = 1; i <= N; ++i) {
        int a; cin >> a;
        v[i] = v[i-1] + a;
    }

    long long ans = 0;
    for (int i = 0; i <= N; ++i) {
        auto itr = lower_bound(v.begin(), v.end(), K + v[i]);
        long long dist = distance(itr, v.end());
        ans += dist;
    }
    
    cout << ans << endl;
    return 0;
}