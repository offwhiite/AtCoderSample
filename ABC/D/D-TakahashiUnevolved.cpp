#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * 強さYを超えないようにA,Bを選ぶ、つまりAとBのうち小さい方を選ぶ方法
 * - ただし全探索するとTLE
 */
int main() {
    long long X,Y,A,B;
    cin >> X >> Y >> A >> B;

    // 仮にAが2(min)だとして高々64回
    long long count = X;
    long long ans = 0;
    // オーバーフローするかもしれないので、そのような場合は弾く
    if (Y/X < A) {
        cout << (Y - X - 1) / B << endl;
        return 0;
    }
    // Aが0~64の間、Bの回数は何回になるかを検討し、一番を多いものを選ぶ
    for (int i = 0; count < Y; ++i) {
        long long BCount = (Y - count - 1) / B;
        ans = max (ans , BCount + i);
        count *= A;
    }
    cout  << ans << endl;
    return 0;
}