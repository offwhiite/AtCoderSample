#include<iostream>
#include <math.h>
#include <vector>
#include <map>
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
      
    spf.erase(spf.begin());spf.erase(spf.begin());

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

/**
 * 約数の数を計算する関数
 */
int calcDivisorNum(int N) {
    if (N == 0 || N==1) return 0;
    vector<int> spf = getPrimeNumberList(N);

    // 約数の数を計算する:素数の数を数える
    int tmp=N;
    map <int, int> m;
    while(tmp != 1) {
        for (int i = 0; i < spf.size(); i++) {
            if (tmp % spf[i] == 0) {
                m[spf[i]]++;
                tmp = tmp / spf[i];
                break;
            }
        }
    }

    // 約数の数を計算する:素数の数から約数の数を求める
    int ans=1;
    for (auto a: m){
        ans = ans * (a.second + 1);
    }

    return ans;
}

int main(int argv, char* argc[]) {

    int N=0;
    cin >> N;

    int count = 0;
    for (int i = 1; i <= N; i = i+2) {
        int divisor = calcDivisorNum(i);
        if (divisor == 8) {
            count++;
        }
    }

    cout << endl << count << endl;
}