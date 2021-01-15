#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N, C;
    cin >> N >> C;
    long long end = 0;
    vector <pair<long long, long long> > v;
    for (int i = 0; i < N; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        v.push_back(pair<int,int>(a-1, c));
        v.push_back(pair<int,int>(b, -c));
    }
    sort(v.begin(), v.end());
    long long ans = 0, f = 0, t = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i].first != t) {
            ans += min(C, f) * (v[i].first - t);
            t = v[i].first;
        }
        f += v[i].second;
    }
    
    cout  << ans << endl;
    return 0;
}