#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> v(N,0);
    for (int i = 0; i < N; ++i) cin >> v[i];
    int num = 1;
    int breakCount = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i]==num) {
            num++;
        } else {
            breakCount++;
        }
    }

    if (num == 1) cout << "-1" << endl;
    else cout << breakCount << endl;
    return 0;
}