#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N, M;
    int i, j;
    
    cin >> N >> M >> i >> j;
    
    M = (M << i);


    // マスクを作る
    int mask = 0;
    for (int s = 0; s <= j - i; ++s) {
        mask += 1 << s;
    }
    mask = mask << i;
    cout << mask << endl;
    
    int change = (N ^ M) & mask;
    N ^= change;

    cout << N << endl;
    return 0;
}