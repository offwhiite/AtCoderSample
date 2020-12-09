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
    for (int i = 0; i < N-1; ++i) {
        int count;
        cin >> count;
        v[count - 1]++;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << v[i] << endl;
    }
    cout  << fixed << setprecision(10);
    return 0;
}