#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * パスカルの三角形で組み合わせnCrをとく。
 * - 単純に階乗できない場合はこちら。
 * - nCrを求めるときにnCr以上の物が出てこない
 * - 計算量はO(2n)
 */
vector<vector<long long> > fact(int n, int r) {
  vector<vector<long long> > v(n + 1,vector<long long>(n + 1, 0));

  // 最初にパスカルの三角形の辺に1を入れる。
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }

  // その中の値を計算していく。自分の一つ上の情報二つをたす。
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

long long calcNumOfCombination(long long n, int r){
        long long num = 1;
        for(int i = 1; i <= r; i++){
            num = num * (n - i + 1) / i;
        }
        return num;
}

int main() {
    int N;
    cin >> N;
    vector <int> v(200010,0);
    vector <int> m(N,0);

    // 値のインプットとその数をカウントする
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
        v[m[i]]++;
    }

    // ここでカウントした数の組み合わせを計算する
    vector <long long> c(200010,0);
    long long cSum = 0;
    for (int i = 0; i <= N; ++i) {
        // 一つも数をカウントされていなかったor一つしかない場合、組み合わせは0なので計算しない
        if (v[i] == 0 || v[i] == 1) continue;

        // 組み合わせの数を計算する。添字のところに含める
        c[i] = calcNumOfCombination(v[i], 2);
        // cout << "i = " << i << endl;
        // cout << "v[i] = " << v[m[i]] << endl;
        // cout << "c[i] = " << c[m[i]] << endl;
        cSum += c[i];
        // cout << "csum = " << cSum << endl;
    }

    // 組み合わせの差を計算する
    for (int i = 0; i < N; ++i) {
        int k = m[i]; // 今回取得するボール
        if (v[k] == 0 || v[k] == 1) {
            cout << cSum << endl;
            continue;
        } else if (v[k] == 2) {
            cout << cSum - 1 << endl;
        } else {
            // 組み合わせの差を計算
            long long f = calcNumOfCombination(v[k]-1, 2);
            cout << cSum + (f - c[k]) << endl;
        }   
    }
    return 0;
}