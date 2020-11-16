#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
int main() {

    int N;
    cin >> N;
    
    vector<int> point(N, 0);
    for (int i = 0; i < N; ++i) cin >> point[i];

    long man = 0;
    long long yuTmp = 0;
    int che = 0;

    for (int d : point) {
        man += abs(d);
        yuTmp += (long)powl(d, 2);
        che = max(che, abs(d));
    }

    cout << man << endl;
    cout << fixed << setprecision(15) << sqrtl(yuTmp) << endl;
    cout << che;
    cout << endl;
}