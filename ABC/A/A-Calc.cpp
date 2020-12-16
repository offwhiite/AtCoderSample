#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int a;
    cin >> a;
    long ans = a + a*a + a*a*a;
    cout  << ans << endl;
    return 0;
}