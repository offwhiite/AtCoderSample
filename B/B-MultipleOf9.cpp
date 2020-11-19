#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() {
    string N;
    cin >> N;

    long ans = 0;
    for (int i = 0; i < N.length(); ++i) {
        ans += N[i] - '0';
    }   
    if (ans % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}