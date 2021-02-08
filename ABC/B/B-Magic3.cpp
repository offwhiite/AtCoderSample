#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N, S, D;
    cin >> N >> S >> D;
    vector <pair<long long ,long long> > v(N,pair<long long , long long>());
    for (int i = 0; i < N; ++i) {
        long long x,y;
        cin >> x >> y;
        v[i] = pair<long long, long long>(x,y);
    }

    for (int i = 0; i < N; ++i) {
        if (S > v[i].first && D < v[i].second) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}