#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> a(N,0);
    vector <int> v(100100,0);
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        sum += a[i];
        v[a[i]]++;
    }

    int Q;
    cin >> Q;

    long long b, c;
    for (int i = 0; i < Q; ++i) {
        cin >> b >> c;
        sum += (c - b) * v[b];
        v[c] += v[b];
        v[b] = 0;
        cout << sum << endl;
    }
    
    return 0;
}