#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
const char* alphabet[] = {"z", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y"};

int main() {
    int N;
    cin >> N;
    const int alphabetNum = 26;
    long long sum = alphabetNum;
    int count = 1;
    long long before = 0;
    while(sum < N) {
        long long tmp = alphabetNum;
        for (int i = 0; i < count; ++i) tmp = tmp * alphabetNum;
        before = sum;
        sum = tmp + sum;
        count++;
    }
    int digits = count;
    long long check = N - before;

    long long tmp = check;
    string ans = "";
    for (int i = 0; i < digits; ++i) ans += "a";

    vector<int> v(digits, 0);
    int i = 0;
    while(tmp > alphabetNum) {
        v[i] = tmp%(alphabetNum-1);
        i++;
        tmp = tmp / alphabetNum;
    }

    v[i] = tmp%alphabetNum;
    for(int i = 0; i < digits; ++i) {
        cout << "vi = " << v[i] << endl;
        int add = v[i];
        if (add == -1) add = 25;

        ans[digits-1 - i] += add;
    }

    cout << ans << endl;
    return 0;
}