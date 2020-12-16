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
    long long max=0;
    long long sum=0;
    long long x=0;
    long long position=0;
    // cin >> v[0];
    // position = v[0];
    // cin >> v[1];
    // position += v[0] + v[1];
    // cin >> v[2];
    // position += position + v[2];
    for (int i = 0; i < N; ++i) {
        cin >> x;
        position += position + x;
        if (max < position) max = position;
    }
    
    cout  << max << endl;
    return 0;
}