#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <bit>
using namespace std;

class Team {
    public:
    int a;
    int b;
    int c;
    int d;

    Team() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }

    Team(int a1, int b1, int c1, int d1) {
        a = a1; b=b1; c=c1; d=d1;
    }
};

int popcount(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
};

int main() {
    int N,M,Q;
    cin >> N >> M >> Q;
    vector <Team> v(Q,Team());
    for (int i = 0; i < Q; ++i) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v[i] = Team(a,b,c,d);
    }

    int ans = 0;
    int ansBit = 0;
    for (int bit = 0; bit < 1 << M; ++bit) {
        if (popcount(bit) != N) continue;
        int tmp = 0;
        // bitで1が立っている桁の数列と考える。
        // この数列で各組の得点を計算して、一番高いものを選ぶ
        cout << "bit = " << bit << endl;
        for (int i = 0; i < Q; ++i) {
            // a桁目とb桁目の数字は？
            int abit;
            int bbit;
            int count = 0;
            // ビットで1が立っている桁を探索する
            for (int j = 0; j < M; ++j) {
                if (bit & (1<<j)) {
                    count++; // countは桁の位置
                    if (v[i].a == count) {
                        abit = j + 1;
                    } else if (v[i].b == count) {
                        bbit = j + 1;
                    }
                    cout << j+1 << " ";
                }
            }
            cout << endl;
            if (bbit - abit == v[i].c) {
                cout << "bbit = "<< bbit << " abit = " << abit << " i = " << i << " v[i].d = " << v[i].d << endl; 
                tmp += v[i].d;
            }
        }
        cout << endl;
        if (ans < tmp) {
            ans = tmp;
            ansBit = bit;
        }
    }
    cout << "ansBit = " << ansBit << endl;
    cout << ans << endl;
    return 0;
}