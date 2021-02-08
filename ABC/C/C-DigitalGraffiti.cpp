#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector <vector<char> > v(H,vector<char>(W,'.'));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> v[i][j];
    
    int count = 0;
    for (int i = 1; i < H; ++i) {
        for (int j = 1; j < W; ++j) {
            if (v[i][j-1] != v[i][j] && v[i-1][j-1] == v[i-1][j]) {
                count++;
            }
        }
    }

    for (int i = 1; i < W; ++i) {
        for (int j = 1; j < H; ++j) {
            if (v[j][i-1] != v[j][i] && v[j-1][i-1] == v[j-1][i]) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}