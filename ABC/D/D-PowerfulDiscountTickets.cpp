#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

/**
 * 基本的に最大値を2で割り続ければ良いと考えた。
 * - 初期値ソートして最上位を2で割る
 * - その時、またソートして常に配列の中で一番大きい値を取れば良い
 *  - 計算量がN * NlogNになるのでオーバーしちゃう
 * - 2分探索で要素のところを探し出せば良い？
 *  - vector だとinsert / eraseにNかかるのでN*Nは変わりない
 * - dequeue的なものを使う？
 *  - 優先度つきキューというものがあるらしい。
 *  - ヒープ構造を持っていて、常に優先度が高いものを先頭における。
 *  - https://ufcpp.net/study/algorithm/col_heap.html#:~:text=%E5%84%AA%E5%85%88%E5%BA%A6%E4%BB%98%E3%81%8D%E5%BE%85%E3%81%A1%E8%A1%8C%E5%88%97%EF%BC%88priority%20queue%EF%BC%89%E3%81%A8%E3%81%AF%E3%80%81,%E6%9C%80%E5%88%9D%E3%81%AB%E5%8F%96%E3%82%8A%E5%87%BA%E3%81%95%E3%82%8C%E3%81%BE%E3%81%99%E3%80%82
 *  - top() が1, push(), pop()にlogNかかるのでlogNでいける
 *  - 最終NLogNで行けたのでAC
 */
int main() {
    int N, M;
    cin >> N >> M;
    priority_queue<long long> v;
    for (int i = 0; i < N; ++i) {
        long long d;
        cin >> d;
        v.push(d);
    }

    for (int i = 0; i < M; ++i) {
        long long d = v.top(); v.pop();
        d /= 2;
        v.push(d);
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += v.top(); v.pop();
    }
    
    cout << ans << endl;
    return 0;
}