#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// (x, y) を始点とした BFS をして、(x, y) から最も遠いマスへの距離を答える
int bfs(const vector<string> &v, int x, int y) {
    int H = v.size(), W = v[0].size();
    vector<vector<int> > dist(H, vector<int>(W, -1));
    queue<pair<int,int> > que;

    int res = 0;
    que.push(pair<int,int>(x, y));
    dist[x][y] = 0;
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        res = max(res, dist[x][y]);
        que.pop();

        // 4方向の移動を考える
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x+ dx[dir], ny = y + dy[dir]; // 四方向移動を確かめる
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue; // 壁の向こうを指定しようとしたらダメ
            if (v[nx][ny] == '#') continue; // 壁の場合も移動なし
            if (dist[nx][ny] == -1) { // すでにいったことのある場所には移動しない
                dist[nx][ny] = dist[x][y] + 1;
                que.push(pair<int,int>(nx, ny)); // 次の移動さきへ
            }
        }
    }
    return res;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> v(H);
    for (int i = 0; i < H; ++i) cin >> v[i]; // vector

    int res = 0;
    for (int x = 0; x < H; ++x) {
        for (int y = 0; y < W; ++y) {
            if (v[x][y] == '#') continue; // ＃の場所は開始点にならないのでスキップ
            res = max(res, bfs(v, x, y));
        }
    }
    cout << res << endl;
}