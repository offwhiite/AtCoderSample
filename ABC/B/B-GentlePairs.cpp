#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <pair<int, int> > v(N,pair<int,int>(0,0));
    for (int i = 0; i < N; ++i) {
        int x,y;
        cin >> x >> y;
        v[i] = pair<int,int>(x,y);
    }
    
    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double dx = v[i].first - v[j].first;
            if (dx == 0) continue;
            double dy = v[i].second - v[j].second;
            double calc = dy/dx;
            if (calc <= 1 && calc >= -1) {
                ans++;
            }
        }
    }

    cout  << ans << endl;
    return 0;
}