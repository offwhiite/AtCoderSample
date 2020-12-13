#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;
    int ps = 0;
    int pe = 0;
    int ns = 0;
    int ne = 0;
    int MaxN = N;
    bool isSuccess = true;
    for (int i = 0; i < M; ++i) {
        cin >> ns;
        N -= ns - pe;
        if (N <= 0) {
            cout << "No" << endl;
            return 0;
        }
        cin >> ne;
        N += ne-ns;
        if (N > MaxN) N = MaxN;
        ps = ns;
        pe = ne;
    }

    N -= T - ne;
    if (N <= 0) {
        cout << "No" << endl;
    } else {
        cout  << "Yes" << endl;
    }
    return 0;
}