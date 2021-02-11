#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // グラフ
    vector <vector<int> > v(N+1,vector<int>());

    // 
    vector <int> dp(N+1,-1);
    queue <int> que;
    for (int i = 0; i < M; ++i) {
        int f,t;
        cin >> f >> t;
        v[f].push_back(t);
        v[t].push_back(f);
    }
    dp[0] = 0;
    dp[1] = 0;

    // 先頭は１番目としてqueに入れておく
    que.push(1);

    while(!que.empty()) {
        int position = que.front(); que.pop();
        for (int j = 0; j < v[position].size(); ++j) {
            int p = v[position][j];
            if (dp[p] != -1) continue;
            que.push(p);
            dp[p] = position;
        }
    }

    if (find(dp.begin(), dp.end(), -1) != dp.end()) {
        cout << "No" << endl;
        return 0;
    } 

    cout << "Yes" << endl;
    for (int i = 2; i <= N; ++i) {
        cout << dp[i] << endl;
    }
    
    cout  << fixed << setprecision(10);
    return 0;
}