#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N,X;
    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        long long a; cin >> a;
        if (a!=X) cout << a << " " ;
    }
    cout << endl;
    return 0;
}