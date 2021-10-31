#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ構造


struct Node {
  int data;
  Node* next;
  Node(int d) : data{ d }, next{ nullptr } { }
};

vector<Node> nodeList = vector<Node>();

// 深さ優先探索
vector<bool> seen; // すでに探索済みかどうかを表す。
void dfs(const Graph &G, int v, int depth) {
    seen[v] = true; // v を訪問済にする

    Node n = new Node();
    nodeList[depth]->next = n;
    nodeList[depth] = nodeList->next;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, depth++); // 再帰的に探索
    }
}

/**
 * 深さのリスト
 * - 今の深さをどう持つかが難しいポイント
 * - 幅優先なら持ちやすいか？と思ったけどより難しそう。
 * - 深さ優先にしてみる。再帰中に深さを持っておき、その深さに対応するところに連結ノードを追加してみる
 * @return int 
 */
int main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;
    
    Graph G(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    
    seen.assign(N,false);
    dfs(G, 0, 0); // 頂点から探索開始
    return 0;
}