#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int N;
    long D;
    cin >> N >> D;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        if ( pow(x,2) + pow(y, 2) <= D*D) ans++;
    }

    cout << ans << endl;
}