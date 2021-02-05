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
    vector <pair<int, int> > v(N,pair<int, int>());
    for (int i = 0; i < N; ++i) {
        int a,b;
        cin >> a >> b;
        v[i] = pair<int, int>(b,a);
    }

    sort(v.begin(), v.end());

    int ws = 0;
    for (int i = 0; i < N ; ++i) {
        ws += v[i].second;
        if (ws > v[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}