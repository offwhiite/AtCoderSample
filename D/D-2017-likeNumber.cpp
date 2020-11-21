#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * インプットNに対する素数の数を求める
 */
vector <int> getPrimeNumberList(int N) {
    vector<int> spf;
    int maxPrimeNumber = sqrt(N);
    spf.assign(maxPrimeNumber, 0); // squrtN のサイズをとって全て0を入れる
    for (int i = 0; i <= maxPrimeNumber;i++) {
        spf[i] = i;
    }
      

    // エラトステネスの篩でNまでの素数を計算する
    int squrtN = sqrt(N);
    for(int i = 0;spf[i] <= squrtN; i++) {
        int p = spf[i];
        for (int j = 0; j <= spf.size(); j++) {
            if (p == spf[j]) continue;
            if (spf[j] % p == 0) spf.erase(spf.begin() + j); 
        }
    }

    return spf;
}

int main() {
    int Q;
    cin >> Q;
    vector <int> q(Q+1, 0);
    vector <int> primeNumbers = getPrimeNumberList(Q);

    for (int i = 0; i < Q; ++i) {
        auto containI = find(primeNumbers.begin(), primeNumbers.end(), i);
        auto containI2 = find(primeNumbers.begin(), primeNumbers.end(), (i+1)/2 ); 
        int count = 0;
        if (containI != primeNumbers.end() && containI2 != primeNumbers.end()) {
            count = 1;
        }
        q[i+1] = q[i] + count;
    }
}