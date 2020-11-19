#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long> v(N, 0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    long ans = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int k = i + 1; k < N - 1; ++k) {
            for (int j = k + 1; j < N; ++j) {
                if (v[j] < v[i] + v[k]
                && v[i] != v[k] && v[j] != v[k] && v[i] != v[j]) ans++;
            }
        }
    }

    cout << ans << endl;
}