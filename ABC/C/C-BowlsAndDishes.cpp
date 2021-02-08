#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    vector <pair<long long ,long long> > p(M,pair<long long , long long>(0, 0));
    for (int i = 0; i < M; ++i) {
        long long x,y;
        cin >> x >> y;
        p[i] = pair<long long, long long>(x,y);
    }

    long long K;
    cin >> K;
    vector <pair<long long ,long long> > h(K,pair<long long , long long>(0, 0));
    for (int i = 0; i < K; ++i) {
        long long x,y;
        cin >> x >> y;
        h[i] = pair<long long, long long>(x,y);
    }

    // もしbitが0なら左の皿、1なら右の皿を選ぶとする
    long long ans = 0;
    for (long long bit = 0; bit < (1 << K); ++bit) {
        vector <int> dish(N+1,0);
        for (int i = 0; i < K; ++i) {
            if ((1 << i) & bit) {
                dish[h[i].second] = 1;
            } else {
                dish[h[i].first] = 1;
            }
        }

        int tmp = 0;
        for (int i = 0; i < M; ++i) {
            if(dish[p[i].first] == 1 && dish[p[i].second] == 1) {
                tmp++;
            }
        }
        if (ans < tmp) {
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}