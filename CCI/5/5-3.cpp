#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

void displayData(int n) {
    vector<int> bit = vector<int>();
    while(n!=0) {
        int x = n % 2;
        if (x == 0) {
            bit.push_back(0);
        } else {
            bit.push_back(1);
        }
        n /= 2;
    }
    for (int i = 0; i < bit.size(); ++i) {
        cout << bit[i];
    }
    cout << " ";
}

int main() {
    for (int i = 0; i <= 16; ++i) {
        int N = i;
        displayData(N);
        int maxCount = 1; // 一番小さくて1
        int zeroCount = 0;
        int sequenseCount = 0;
        int zeroPosition = 0;
        while (N != 0) {
            if ((N & 1) == 0 && zeroCount == 0) {
                zeroCount++;
                sequenseCount++;
                zeroPosition = i;
            } else if ((N & 1) == 0 && zeroCount == 1) {
                zeroCount = 1;
                maxCount = max(maxCount, sequenseCount);
                sequenseCount = i - zeroPosition;
                zeroPosition = i;
            } else {
                sequenseCount++;
            }
            N >>= 1;
        }
        maxCount = max(maxCount, sequenseCount);
        cout << maxCount << endl;
    }
    return 0;
}