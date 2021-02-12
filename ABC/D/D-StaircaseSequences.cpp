#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    long long N;
    cin >> N;
    // 初項a, 末項bとしたとき、2N = (a+b)(b-a+1)となる。公差1なので。
    // であるとすると、これらは2Nの約数の掛け算でないと成り立たない
    // また、2Nなので少なくとも2が一回かけられていないといけない上に、片方の項にしか２を置けないため、
    // 2で割り切った値の約数の個数が答えとなる
    while(N%2==0) N/=2;
    long long sqt = sqrt(N), ans = 0;
    for (long long i = 1; i <= sqt; ++i) if(N%i==0) ans+=2; 
    if (sqt * sqt == N) ans--;
    cout  << ans * 2 << endl;
    return 0;
}