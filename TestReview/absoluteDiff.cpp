#include <vector>
#include <math.h>
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
    
    vector<int> v((int)A.size() + 1, 0);

    // 累積和をとる
    for (int i = 0; i < (int)A.size();++i) v[i+1] = v[i] + A[i];
    
    int maxNum = 0;
    for (int p = 1; p < (int)A.size();++p) {
        int num = abs(v[p] - v[A.size()]);
        if (maxNum < num) maxNum = num;
    }

    return maxNum;
}

vector<int> createArrayWithMissing(int size) {
    vector<int> m;
    for (int i = 1; i < size; ++i) {
        m.push_back(100000);
    }
    return m;
}

int main() {
    vector<int> v = createArrayWithMissing(100000);
    cout << solution(v) << endl;
}