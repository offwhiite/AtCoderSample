#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N, X;
    long long sum = 0;
    cin >> N >> X;
    vector <pair<long long, long long> > d(N,pair<long long ,long long>(0,0));
    for (int i = 0; i < N; ++i) {
        int v,p;
        cin >> v >> p;
        d[i] = pair<long long, long long> (v,p);
    }

    for (int i = 0; i < N; ++i) {
        sum += d[i].first * d[i].second;
        if (sum > X * 100) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}