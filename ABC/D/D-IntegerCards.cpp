#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector <int> v;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<pair<long long,long long> > p(M, pair<long long, long long>());
    for (int i = 0; i < M; ++i) {
        int b,c; cin >> b >> c;
        p[i] = pair<long long, long long>(c,b);
    }
    
    sort(p.begin(), p.end(), greater<long long>());

    

    cout  << fixed << setprecision(10);
    return 0;
}