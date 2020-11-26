#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int H,W,K;
    cin >> H >> W >> K;
    vector<vector<string> > v(H,vector<string>(W,"."));
    for (int i = 0; i < H; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < W; ++j) {
            v[i][j] = row[j];
        }
    }

    vector<vector<string> > tmp(H,vector<string>(W,"."));
    
    int ans = 0;
    for (int h = 0; h < 1 << H; ++h) {
        for (int w = 0; w < 1 << W; ++w) {
            copy(v.begin(), v.end(), tmp.begin());
            int count = 0;
            // 作成フェーズ
            // 行を赤で塗りつぶす
            for (int i = 0; i < H ; ++i) {
                if (h & 1 << i) {
                    for (int j = 0; j < W; ++j) tmp[i][j] = ",";
                }
            }
            // 列を赤で塗りつぶす
            for (int i = 0; i < W; ++i) {
                if (w & 1 << i) {
                    for (int j = 0; j < H; ++j) tmp[j][i] = ",";
                }
            }

            // 探索フェーズ
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < W; ++j) {
                    if (tmp[i][j] == "#") count++;
                }
            }
            if (count == K) { 
                ans++;
            }
        }
    }

    cout  << ans << endl;
    return 0;
}