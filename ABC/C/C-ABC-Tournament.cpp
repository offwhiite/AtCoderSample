#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long s = 1 << N;

    vector <int> v(s,0);
    vector <int> c(s,0);
    for (int i = 0; i < s; ++i) cin >> v[i];

    copy(v.begin(), v.end(), c.begin());
    
    int ans = 0;
    for (int j = 1; j <= N; ++j) {
        long long m = 1 << (N - j);
        vector <int> w;
        for (int i = 1; i <= m; ++i) {
            int f = 2 * i - 1;
            int second = 2 * i;
            if (v[f-1] > v[second-1]) {
                w.push_back(v[f-1]);
                ans = v[second-1];
            } else {
                w.push_back(v[second-1]);
                ans = v[f-1];
            }
        }
        v = w;
    }
    vector<int>::iterator d = find(c.begin(), c.end(),ans);
    cout << distance(c.begin(), d) + 1 << endl;
    return 0;
}