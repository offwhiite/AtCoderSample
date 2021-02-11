#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N, X ,Y;
    cin >> N >> X >> Y;
    vector<vector <int> > g(N+1,vector<int>());
    for (int i = 1; i < N; ++i) {
        g[i].push_back(i+1);
        g[i+1].push_back(i); // 無向グラフなので
    }
    g[X].push_back(Y);
    g[Y].push_back(X);

    vector<vector<int> > dist(N+1, vector<int>(N+1, -1)); // 距離を入れる箱

    // スタート位置をsとして、全探索する
    for (int s = 1; s <= N; ++s) {
        queue<int> que;
        que.push(s);
        dist[s][s] = 0; // 初期位置から初期位置へは0
        while(!que.empty()) {
            // 次探索するポイントをキューから取得する
            int now = que.front(); que.pop();
            for (int nv : g[now]) {
                if(dist[s][nv] != -1) continue;
                dist[s][nv] = dist[s][now] + 1; // 距離は今の地点からそこに移動するまでは1固定（今回は）
                que.push(nv); 
            }
        }
    }

    // 全ての探索を終えたので、次は距離ごとの個数を数える
    // distにはsを起点としたときの最短距離が格納されているので、それを要素として見つかれば+1する
    // ただし、1から見て2は見て良いが、2からみて1は見てはいけない。（重複するので）
    // また、[x][x](初期位置to初期位置)は必ず0になるのでいらない。
    vector <int> res(N+1,0);
    for (int i = 1; i <= N; ++i) {
        for(int j = i+1; j <= N; ++j) res[dist[i][j]]++;
    }

    for (int i = 1; i < N; ++i) cout << res[i] << endl;
    
    return 0;
}