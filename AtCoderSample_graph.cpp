#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>; // グラフ構造

// 深さ優先探索
vector<bool> seen; // すでに探索済みかどうかを表す。
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;
    
    Graph G(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        // 無向グラフなら以下を追加
        // G[b].push_back(a);
    }
    
    seen.assign(N,false);
    dfs(G, 0); // 頂点から探索開始
    return 0;
}