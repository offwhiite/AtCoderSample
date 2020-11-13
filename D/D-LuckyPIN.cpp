#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main() {
    int N = 0;
    string S;
    cin >> N;
    cin >> S;


    int ans =0;
    for (int i=0;i < 1000;i++) {
        int c[3] = {i/100, i/10%10, i%10};
        int count = 0;
        for (int j=0; j<S.length();j++) {
            if (S[j] == c[count] + '0') {
                count++;
            }
            if (count == 3) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}