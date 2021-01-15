
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * 白のマスの中で一番小さいものがはんことなる
 * そのハンコで空白のマスを割って、かつあまりが出たら＋１するというロジック
 */
int main() {
    long long N, M;
    cin >> N >> M;

    vector <long long> v(M,0);
    for (int i = 0; i < M; ++i) cin >> v[i];
    sort(v.begin(), v.end()); // -1するときオーバーしちゃうため。
    v.insert(v.begin(), 0);
    v.push_back(N+1);
    vector <long long> d;
    // 空白のマスをdに入れる
    long long h = N;
    for (int i = 0; i + 1 < v.size(); ++i) {
        long long x = v[i+1] - v[i] - 1;
        if (x > 0) {
            d.push_back(x);
            h = min(h,x);
        }
    }
    long long ans = 0;
    for (auto len : d) {
        ans += (len + h - 1)/h;
    }
    cout << ans << endl;
    return 0;
}