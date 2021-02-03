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
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());
    int count = 0;
    for (int i = 0; i < N-2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            auto c = lower_bound(v.begin(), v.end(), v[j] + v[i]); // c < b + a　より、cの位置を二分探索で求める
            long long ng = distance(c, v.end()); // ngのエリアを求める。cからNまでの要素は全て要件を満たさない。
            count += ((N - 1) - j) - ng; // あとはc > b-aから、今回ソート済みなのでb以下は全て要件を満たさない。
        }
    }
    
    cout << count << endl;
    return 0;
}