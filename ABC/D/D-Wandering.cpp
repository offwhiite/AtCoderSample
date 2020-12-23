#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long x=0;
    long long position=0;
    long long sum = 0;
    vector <long long> v(N+1,0);
    vector <long long> s(N+1,0);
    vector <long long> m(N+1,0);

    // 累積和の最大値が0ならばもうどうあがいてもプラスにならないので
    // 0を入れて終了
    // - 作戦としては累積和の累積和が最大になる値 + 入力値が最大になる累積和を足す
    // 例) -2 1 3 -1 -1の時
    // 累積和 v[i] = {-2, -1, 2, 1, 0}
    // 累積和の累積和 s[i] = {-2, -3, -1, 0, 0}

    for (int i = 0; i < N; ++i) {
        cin >> x;
        v[i+1] = v[i] + x;
        m[i+1] = max(m[i], v[i+1]);
        s[i+1] = s[i] + v[i+1];
        // cout << "s[i] = " << s[i+1] << endl;
        // cout << "v[i] = " << v[i+1] << endl;
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, s[i] + m[i]);
    }
    ans = max(ans, s[N]);
    if (ans <= 0) {
        cout << "0" << endl;
        return 0;
    }

    cout  << ans << endl;
    return 0;
}