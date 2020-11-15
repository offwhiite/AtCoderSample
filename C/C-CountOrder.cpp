#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // 数列
    vector<int> v(N,0);
    for (int i = 0; i < N; ++i) v[i] = i + 1;
    
    // 数列P
    vector<int> p(N, 0);
    for (int i = 0; i < N; ++i) cin >> p[i];

    // 数列Q
    vector<int> q(N, 0);
    for (int i = 0; i < N; ++i) cin >> q[i];

    int count = 1;
    int a = 0,b = 0;
    do {
        bool isMatchP = true;
        bool isMatchQ = true;
        for (int i = 0; i < N; ++i) {
            if (v[i] != p[i]) isMatchP = false;
            if (v[i] != q[i]) isMatchQ = false;
        }
        if (isMatchP) a = count;
        if (isMatchQ) b = count;
        count++;
    } while(next_permutation(v.begin(), v.end()));

    cout << abs(a-b) << endl;
}