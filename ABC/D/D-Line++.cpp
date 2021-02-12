#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    --X, --Y;
    vector<vector<int> > dist(N, vector<int>(N, -1));
    for (int s = 0; s < N; ++s) {
        queue<int> que;
        que.push(s);
        dist[s][s] = 0;
        while (!que.empty()) {
            auto v = que.front(); que.pop();
            vector<int> nvs;
            if (v > 0) nvs.push_back(v-1);
            if (v < N-1) nvs.push_back(v+1);
            if (v == X) nvs.push_back(Y);
            if (v == Y) nvs.push_back(X);
            for (auto nv : nvs) {
                if (dist[s][nv] == -1) {
                    dist[s][nv] = dist[s][v] + 1;
                    que.push(nv);
                }
            }
        }
    }
    vector<int> res(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) res[dist[i][j]]++;
    }
    for (int d = 1; d < N; ++d) cout << res[d] << endl;
}