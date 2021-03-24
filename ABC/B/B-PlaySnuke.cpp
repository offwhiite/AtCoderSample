#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = INT32_MAX;
    for (int i = 0; i < N; ++i) {
        int A,P,X; cin >> A >> P >> X;
        if (A < X) {
            ans = min(ans, P);
        }
    }
    if (ans == INT32_MAX) ans = -1;
    cout << ans << endl;
    return 0;
}