#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int X, N;
    cin >> X >> N;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    
    if (count(v.begin(), v.end(), X) == 0) {
        cout << X << endl;
        return 0;
    }
    
    for(int i = 0; i <= X + 1; ++i) {
        if (count(v.begin(), v.end(), X-i) ==0) {
            cout << X-i << endl;
            break;
        }
        if (count(v.begin(), v.end(), X+i) ==0) {
            cout << X+i << endl;
            break;
        }
    }

    return 0;
}