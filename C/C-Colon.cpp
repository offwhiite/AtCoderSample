#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int A,B,H,M;
    cin >> A >> B >> H >> M;
    double angle = 0;
    int minute = M + H * 60;
    double hAngle = 0.5 * minute;
    double mAngle = 6 * M;
    angle = abs(hAngle - mAngle);
    double distance2 = (A * A) + (B * B) - (2 * A * B * cos(M_PI * angle / 180));
    double distance = sqrt(distance2);
    cout  << fixed << setprecision(15) << distance << endl;
    return 0;
}