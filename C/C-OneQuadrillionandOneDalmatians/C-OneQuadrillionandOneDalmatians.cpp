#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N;
    cin >> N;
    const int alphabetNum = 26;
    string ans = "";
    while(N) {
        --N;
        ans += (char)('a' + N%alphabetNum);
        N = N / alphabetNum;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}