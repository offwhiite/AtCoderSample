#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long A,B;
    cin >> A >> B;
    long long S = A * B;
    int div = B;
    int d = A;
    while(d%div != 0) {
        int tmp = div;
        div = d % div;
        d = tmp;
    }
    long long ans = S / div;
    cout << ans << endl;
    return 0;
}