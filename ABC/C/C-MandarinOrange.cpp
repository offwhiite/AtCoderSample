#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <long long> v(N + 1,0);
    for (int i = 0; i < N; ++i) cin >> v[i];

    long long ans = 0;
    long long tmp = 0;

    for (int l = 0; l < N; ++l) {
        long long x = v[l];
        for (int r = l; r < N; ++r) {
            x = min (x, v[r]);
            ans = max(ans, x*(r-l+1));
        }
    }
    cout << ans << endl;
    return 0;
}