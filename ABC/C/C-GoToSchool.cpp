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
    vector <pair<int, int> > v(N,pair<int,int>());
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        v[i] = pair<int,int>(a,i+1);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; ++i) {
        cout << v[i].second << " ";
    }
    cout << endl;
    return 0;
}