#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    for (int i = 0; i <= 16; ++i) {
        int N = i;
        vector<int> bit = vector<int>();
        while(N!=0) {
            int x = N % 2;
            if (x == 0) {
                bit.push_back(0);
            } else {
                bit.push_back(1);
            }
            N /= 2;
        }
        for (int i = 0; i < bit.size(); ++i) {
            cout << bit[i];
        }
        cout << " ";

        int maxCount = 0;
        int zeroCount = 0;
        int sequenseCount = 0;
        int zeroPosition = 0;
        for (int i = 0; i < bit.size(); ++i) {
            if (bit[i] == 0 && zeroCount == 0) {
                zeroCount++;
                sequenseCount++;
                zeroPosition = i;
            } else if (bit[i] == 0 && zeroCount == 1) {
                zeroCount = 1;
                maxCount = max(maxCount, sequenseCount);
                sequenseCount = i - zeroPosition;
                zeroPosition = i;
            } else {
                sequenseCount++;
            }
        }
        maxCount = max(maxCount, sequenseCount);
        cout << maxCount << endl;
    }
    return 0;
}