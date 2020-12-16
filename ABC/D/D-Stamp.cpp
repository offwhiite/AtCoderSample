
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main() {
    int N, M;
    cin >> N >> M;
    vector <int> v(M,0);
    for (int i = 0; i < M; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    vector <int> d(M+1,0);
    d[0] = v[0] - 1;
    for (int i = 1; i < M; ++i) {
        int x = v[i] - v[0] - 1;
        if (x != 0) d[i] = x;
    }
    d[M] = N - v[M-1];
    int ans = d[0];
    for (int i = 0; i < d.size(); ++i) cout << d[i] << endl;
    for (int i = 1; i < d.size(); ++i) {
        if (ans == 0) {
            ans = d[i];
            continue;
        }
        ans = gcd(ans, d[i]);
    }
    sort(d.begin(), d.end());
    int k = d[0];
    if (d[0]==0) {
        k = d[1];
    }

    cout  << ans << endl;
    return 0;
}