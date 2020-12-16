#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * いもす法を利用する
 * - 開始と終了のみカウントし、その値の累積話をとる 
 */
int main() {
    long long N, W;
    cin >> N >> W;
    vector <long long> v(200000,0);
    for (int i = 0; i < N; ++i) {
        long long s,t,p;
        cin >> s >> t >> p;
        v[s]+=p;
        v[t]-=p;
    }

    for (int i = 0; i < 200000; ++i) {
        if(0<i)v[i] += v[i-1];
        if (v[i] > W) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}