#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N,M;
    cin >> N>>M;
    vector <int> high(N,0);
    vector <int> list(N,1);
    for (int i = 0; i < N; ++i) cin >> high[i];
    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        if (high[from] > high[to]) {
            list[to] = 0;
        } else if(high[from] < high[to]) {
            list[from] = 0;
        } else if(high[from] == high[to]) {
            list[to] = 0;
            list[from] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (list[i]==1) ans++;
    }

    cout << ans << endl;
    return 0;
}