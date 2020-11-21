#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    long long X;
    cin >> X;

    long long money = 100;
    long long ans = 0;
    while(money < X) {
        ans++;
        money = money + money * 0.01;
    }

    cout << ans << endl;
    long long test = 999999999999999;
    long long tmp = test * (double)0.01;
    long long tmp2 = test / 100;
    cout  << fixed << setprecision(16) << tmp << endl;
    cout << tmp2 << endl;
    long long ans2 = test + test * 0.01;
    long long ans3 = test + test / 100;
    cout << fixed << setprecision(15) << ans2 << endl;
    cout << fixed << setprecision(15) << ans3 << endl;
    
    return 0;
}