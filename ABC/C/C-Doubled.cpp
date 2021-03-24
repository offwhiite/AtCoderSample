#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (to_string(N).size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    long long X = 1;
    if (to_string(N).size() % 2 != 0) {
        for (int i = 1; i < to_string(N).size(); ++i) X *= 10;
        X -= 1;
    } else {
        X = N;
    }

    int size = to_string(X).size() / 2;
    long long d = 1;
    for (int i = 0; i < size; ++i) d *= 10;

    long long b = X / d;
    long long a = X % d;

    if (b > a) b--;
    
    cout <<b<< endl;
    return 0;
}