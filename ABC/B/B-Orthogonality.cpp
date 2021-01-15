#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    vector <int> b(N,0);
    for (int i = 0; i < N; ++i) cin >> b[i];
    
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += v[i] * b[i];
    }

    if (sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}