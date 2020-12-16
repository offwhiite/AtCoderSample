#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N,M,X;
    cin >> N >> M >> X;
    vector <vector<int> > v(N, vector<int>(M+1,0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M+1; ++j) {
            cin >> v[i][j];
        }
    }

    int ans = INT32_MAX;
    for (int bit = 0; bit < 1 << N; ++bit) {
        vector<int> comprehensions(M,0);
        int money = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & 1 << i) {
                for(int j = 0; j < M; ++j) comprehensions[j] += v[i][j+1];
                money += v[i][0];
            }
        }
        bool isSuccess = true;
        for(int j = 0; j < M; ++j) if(comprehensions[j] < X) isSuccess = false;
        if(isSuccess && ans > money) ans = money;
    }
    if (ans == INT32_MAX) ans = -1;
    
    cout << ans << endl;
    return 0;
}