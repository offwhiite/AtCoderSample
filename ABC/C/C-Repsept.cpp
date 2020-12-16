#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    long long K;
    cin >> K;

    int ans = 7 % K;
    for (int i = 0; i < K; ++i) {
      if (ans == 0) {
        cout << i + 1 << endl;
        return 0;
      }
      ans = (ans * 10 + 7) % K;
    }

    cout << "-1" << endl;
    return 0;
}