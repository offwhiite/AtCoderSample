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
    vector <double> p(N+1,0);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        double d = (v[i] * (v[i] + 1)) / 2;
        double a = (double)d / v[i];
        p[i + 1] = p[i] + a;
    }
    
    double ans = 0;
    for (int i = 0; i < N - K + 1; ++i) {

        double tmp = p[i + K] - p[i];
       
        if (ans < tmp) {
            ans = tmp;
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}