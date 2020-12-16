#include <iostream>
using namespace std;

int multipleOfThreeDigit(string N) {
    int ans = N.length();
    for (long long bit = (1 << N.length()) - 1 ; bit >= 0; --bit) {
        string tmp = "";
        for (int i = 0; i < N.length(); ++i) {
            if (bit & (1 << i)) {
                tmp = N[i] + tmp;
            } 
        }
        if (tmp == "") continue;
        if (atoll(tmp.c_str()) % 3 == 0) {
            int count = N.length() - tmp.length();
            if (ans > count) {
                ans = count;
            }
        }
    }
    if (ans == N.length()) {
        ans = -1;
    }
    return ans;
}

int main() {
    string N;
    cin >> N;

    cout << multipleOfThreeDigit(N) << endl;
}