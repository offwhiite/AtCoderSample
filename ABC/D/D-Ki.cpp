#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
using Graph = vector<vector<int> >; // グラフ構造

// 深さ優先探索
vector<bool> seen; // すでに探索済みかどうかを表す。
void dfs(const Graph &G, int next, int back, vector<long long> &res) {
    if (back != -1) res[next] += res[back]; // もし親が存在すれば、親の値を足す。
    seen[next] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[next]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, next, res); // 再帰的に探索
    }
}

/**
 * 考え方
 * - グラフを作成して深さ優先探索を行う
 * - ただし毎回深さ優先探索をしてたら最大N*Qの計算量で間に合わない
 * - であれば対象のルートに数字を足しておいて、最後に深さ優先探索による累積和をとる
 */
int main() {
    int N, Q;
    cin >> N >> Q;
    Graph G(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<long long> pl(N,0); // いもす法として、各頂点をスタートとするポイントを付与しておく
    for (int i = 0; i < Q; ++i) {
        int p, x;
        cin >> p >> x;
        --p;
        pl[p] += x;
    }  

    seen.assign(N,false); // 行ったかどうかの情報の初期化
    
    // 頂点から確認
    dfs(G, 0, -1, pl);

    for (int i = 0; i < N; ++i) cout << pl[i] << " ";
    cout << endl;
    return 0;
}