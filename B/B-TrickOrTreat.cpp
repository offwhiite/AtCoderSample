#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector <int> v(N,0);
    int ans = N;
    for (int i = 0; i < K; ++i) {
        int d = 0;
        cin >> d;
        for (int j = 0; j < d; ++j) {
            int a;
            cin >> a;
            if (v[a-1]==0) {
                v[a-1] = 1;
                ans--;
            }
        }
    }
    
    cout  << ans << endl;
    return 0;
}