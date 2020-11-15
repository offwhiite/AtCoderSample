#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include <iomanip>
using namespace std;

int main() {
    double Sx, Sy, Gx ,Gy;
    cin >> Sx >> Sy >> Gx >> Gy;

    double x,y;
    x = (Sy + Gy) / (Sx - Gx);
    y = Sy - (Sx * x);

    cout << fixed << setprecision(10) << (y *-1) / x;
}