#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    int ans = 0;
    while (N >= W*ans) ans++;
    
    cout  << ans - 1 << endl;
    return 0;
}