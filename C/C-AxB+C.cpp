#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (long a = 1; a < N; ++a) {
        ans += (N-1) / a;
    }

    cout << ans << endl;
    return 0;
}