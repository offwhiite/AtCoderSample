#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    const long long length = 10000000000;
    int N;
    cin >> N;
    string T;
    cin >> T;
    // Tが入る110の連結にさらに一つ連結させた文字列を考える
    string subS;
    for(int i = 1;subS.size() < N; ++i) subS += "110";
    subS+="110";
    long long tmp = 0;
    for (int i = 0; i < 3;i++) {
        bool isMatch = true;
        for (int j = 0; j < T.size();j++) {
            if(subS[i+j] != T[j]) {
                isMatch = false;
                break;
            }
        }
        if (isMatch) {
            tmp++;
        }
    }
    int h = 0;
    if (T[T.size()-1] == '0') {
        h++;
    }
    if (T=="1") {
        cout << length * 2 << endl;
    } else if (T=="110"||T=="11"||T=="10"||T=="0") {
        cout << length << endl;
    } else if (T=="011"||T=="101"||T=="01") {
        cout << length - 1 << endl;
    } else if (tmp == 1) {
        cout << length - (N / 3) + h << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}