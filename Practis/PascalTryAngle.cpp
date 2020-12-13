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