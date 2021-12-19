#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>; // グラフ構造

/**
 * 平衡チェック
 * - 深さ優先での探索を考えたが、その枝のMaxを把握するのが予想以上に難しかった
 * - 幅優先で検索していき、キューに詰めるものがなくなったノードが発見されてから2回続いたら高さの差があるとする
 * 
 * @return int 
 */
int main() {
    int V, E;
    cin >> V >> E;
    int s, t;
    cin >> s >> t;
    Graph G(V);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back({b});
    }
    vector<bool> seen(V, false);  // 既に見たことがある頂点か記録する
    queue<int> que;
    que.emplace(0);
    seen[s] = true;
    bool isLast = false;

    // 幅優先探索
    while (que.size() != 0) {     
        int state = que.front();  // 現在の状態
        que.pop();

        // 次に至るノードがなかったら0になるはず
        if (G[state].size() == 0) {
            isLast = true;
        }
        for (auto next : G[state]) {
            if (!seen[next]) {  // 未探索の時のみ行う
                seen[next] = true;
                que.emplace(next);  //次の状態をqueueへ格納
            }
        }
    }
    if (seen[t]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}