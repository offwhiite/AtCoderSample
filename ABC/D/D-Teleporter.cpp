#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    long long N,K;
    cin >> N >> K;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];

    // 最初にループする街の数を計算する
    int p = 0;
    int count = 0;
    int init = 0;
    long long d = K;
    if (K > N) {
        map<int, int> m; // 1の街に帰ってくるとは限らないので、同じ街が出てきたらループに入ると判定する
        // またループに入らないが通る街もあり、それをカウントしてKから一回引く必要がある
        m[p]++;
        do {
            p = v[p];
            p--; // 添字対応
            m[p]++;
        } while(m[p] <= 1);

        // ループのスタートポジションを保持(添字)
        int rsp = p;

        // 1 to P と P to Pの数を数える
        p = 0;
        int firstP = 0;
        do {
            p = v[p];
            p--; // 添字対応
            firstP++;
        } while(p != rsp);
        
        p = rsp;
        int PtoP = 0;
        do {
            p = v[p];
            p--; // 添字対応
            PtoP++;
        } while(p != rsp);

        // 次にあまりを求める
        // cout << "K = " << K << " firstP = " << firstP << " PtoP = " << PtoP << " rsp = " << rsp << endl;
        d = (K - firstP) % PtoP;

        // 探索
        p = rsp + 1; // 添字対応
        for (int i = 0; i < d; ++i) p = v[p-1];
    } else {
        p = 1;
        for (int i = 0; i < d; ++i) p = v[p-1];
    }

    cout << p << endl;
    return 0;
}