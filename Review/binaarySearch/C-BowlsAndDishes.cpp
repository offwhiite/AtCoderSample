#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

/**
 * Kが16であることに着目すると、bit全探索で対応できそう
 * - 例えばCのさらに置いた時は0, Dの皿に置いた時は1とする
 * - この時選ばれたお皿で何個条件が満たされるかをチェックする
 */
int main() {
    int N,M;
    cin >> N >> M;
    vector <pair<int,int> > v(M,pair<int,int>());
    for (int i = 0; i < M; ++i) {
        int a,b;
        cin >> a >> b;
        v[i] = pair<int, int>(a,b);
    }

    int K;
    cin >> K;
    vector <pair<int,int> > dish(K,pair<int,int>());
    for (int i = 0; i < K; ++i) {
        int c,d;
        cin >> c >> d;
        dish[i] = pair<int, int>(c,d);
    }

    int ans = 0;
    for (long long bit = 0; bit < (1 << K); ++bit) {
        map<int, int> m; 
        for(int i = 0; i < K; ++i) {
            if (bit & (1<<i)) m[dish[i].first] = 1;
            else m[dish[i].second] = 1;
        }

        int count = 0;
        for(pair<int,int> c : v) {
            if (m[c.first] == 1 && m[c.second] == 1) {
                count++;
            }
        }

        if (ans < count) {
            ans = count;
        }
    }
    
    cout << ans << endl;
    return 0;
}