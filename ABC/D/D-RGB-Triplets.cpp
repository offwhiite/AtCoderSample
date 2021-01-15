#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    long long R = 0,G = 0,B = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') R++;
        else if(S[i] == 'G') G++;
        else B++;
    }

    int count = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i+1; j + (j - i) < N; ++j) {
            int k = j + j - i;
            if (S[i] != S[j] && S[j] != S[k] && S[i] != S[k]) count++;
        }
    }
    long long ans = R * G * B - count;
    cout  << ans << endl;
    return 0;
}