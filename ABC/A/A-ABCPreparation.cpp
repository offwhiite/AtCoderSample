#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int a,b,c,d;
    int min = INT32_MAX;
    for (int i=0; i < 4; ++i) {
        int tmp = 0;
        cin >> tmp;
        if (min > tmp) min = tmp;
    }
    cout  << min << endl;
    return 0;
}