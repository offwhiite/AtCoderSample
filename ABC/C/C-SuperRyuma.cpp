#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
  int r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  
  // r1,c1を原点(0,0)として考えると目的地は(r2-r1, c2-c1)
  // それがr1-r2でもc1-c2でも手数は変わらないので絶対値とする
  long long p = abs(r2-r1);
  long long q = abs(c2-c1);
  
  // A,B,Cの移動手段を組み合わせると最大３手で必ずたどり着ける
  int ans = 3;
  
  // もし目的地(r2-r1, c2-c1)が原点なら０手
  if (p == 0 && q == 0) ans = 0;
  
  // 一手で行ける範囲はA,B,C内
  // つまり |p|-|q| == 0 (pとqが同じ値の場合)
  // もしくはCでいける目的地までの距離が3以下(3,0),(2,1),(1,2),(0,3)
  else if (p - q == 0 || p + q <=3) ans = 1;
  
  // 二手で行ける範囲はA,B,Cの組み合わせ
  // A,B = p + q % 2 == 0 (AとBを組み合わせれば今いる場所から偶数盤目のところにいける)
  // A or B , C = |p-q| <= 3 (pとqの差が3以内だったらCで動いてあとはA,Bで一手でいける)
  // C,C = p+q <=6 (二回Cで移動した場合)
  else if ((p + q) % 2 == 0 || abs(p-q) <= 3 || p + q <= 6) ans = 2;
  
  // これら以外であれば3手となる
  cout  << ans << endl;
  return 0;
}