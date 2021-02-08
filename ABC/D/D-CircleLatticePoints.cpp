#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main(void){
    long double a,b,r;
    cin >> a >> b >> r;
    r += 1e-14;
    // 格子点がでてきうる最小の整数値と最大の整数値を求める
    int start = ceil(a - r);
    int end = floor(a + r);
    long long ans = 0;
    for(long long i = start; i <= end; ++i){
        // start <= x <= end の間の整数値で三平方の定理を使って距離計算して、それがy軸の中に何個あるかを確認する
        long double r2 = r * r;
        long double d = (a-(double)i) * (a-(double)i);
        long double t = r2 - d;
        long double p = sqrtl(t);

        long double tmp1 = (long double)b-p;
        long double bottom = ceil(tmp1);
        long double tmp2 = (long double)b+p;
        long double top = floor(tmp2);
        // for (long long t = bottom; t <= top; t+=10000) ans++;
        ans += top - bottom + 1; 
        // cout << bottom << " " << top << " " << ans << endl;
        
    }
    cout << ans << endl;
    return 0;
}