#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
int main() {
    long double W,H,x,y;
    cin >> W >> H >> x >> y;
    int c = 0;
    if (W/2 == x && H/2 == y) c=1;
    cout << fixed << (long double)W * H / 2 << " " << c << endl;
    return 0;
}