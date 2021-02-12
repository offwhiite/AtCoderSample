#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    double a, b, x;
    cin >> a >> b >> x;

    x /= a;
    const double PI = acos(-1.0);
    cout << fixed << setprecision(10);
    if (x > a*b/2) cout << atan2((a*b-x)*2, a*a) * 180 / M_PI << endl;
    else cout << atan2(b*b, x*2) * 180 / M_PI << endl;
    return 0;
}