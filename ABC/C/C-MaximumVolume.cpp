#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int L;
    cin >> L;
    cout  << fixed << setprecision(10) << pow((double)L/3,3.0) << endl;
    return 0;
}