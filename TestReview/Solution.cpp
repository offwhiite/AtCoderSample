// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

/**
 * 0を起点とし、自分より大きい1の数が何個あるかを数え上げる。
 * - 0 or 1 なので累積和を使えば早くなりそう
 * - あとは1の時skipするよりはpairで計算圧縮した方が良いかどうか...
 * - 二回目のforNは小さくなるけど、一回めの処理が2倍になるので愚直にやった方が良いかもしれない
 * - 値の範囲は100,000がMax。int型で良さそう
 * - 1,000,000,000を超えたら-1を返すらしい。配列の大きさの制限的に累積和の途中でreturnしないとダメ。
 */
#include <vector>
#include <iostream>
using namespace std;
const int SOLUTION_MAX = 1000000000;
int solution(vector<int> &A) {
    vector<int> v(A.size() + 1, 0);

    // 累積和を計算する
    for (int i = 0; i < (int)A.size(); ++i) {
        v[i+1] = v[i] + A[i];
        if (v[i+1] > SOLUTION_MAX) return -1;
    }

    int ans = 0;
    for (int i = 0; i < (int)A.size(); ++i) {
        if (A[i] == 1) continue;
        ans += v[A.size()] - v[i+1];
        if (ans > SOLUTION_MAX) return -1;
    } 
    
    return ans;
}
vector<int> createArrayWithMissing(int size) {
    vector<int> m;
    for (int i = 1; i < size; ++i) {
        m.push_back(100000);
    }
    return m;
}

int main() {
    vector<int> v = createArrayWithMissing(100000);
    cout << solution(v) << endl;
}