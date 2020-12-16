#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    string N;
    cin >> N;

    string ans;
    if (N[N.length()-1] == 's') {
        ans = N + "es";
    } else ans = N + "s";

    cout << ans << endl;
}