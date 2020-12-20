#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    vector < vector <int> > v(H,vector<int>(W,0));
    int min = 101;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> v[i][j];
            if (min > v[i][j]) min = v[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            count += v[i][j] - min;
        }
    }
    
    cout  << count << endl;
    return 0;
}