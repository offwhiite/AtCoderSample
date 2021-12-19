#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

vector<int> displayData(int n) {
    vector<int> bit = vector<int>();
    while(n!=0) {
        int x = n % 2;
        if (x == 0) {
            bit.push_back(0);
        } else {
            bit.push_back(1);
        }
        n /= 2;
    }
    for (int i = bit.size() -1; i >= 0; --i) {
        cout << bit[i];
    }
    cout << " ";
    return bit;
};

int toDecimal(vector<int> v) {
    int decimal = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

/**
 * @brief 隣の数
 * - bit的に考えると最下位ビットを空いている0に移動するということだと思う
 * - 1. 最下位の1ビットを見つける
 * - 2. 見つけた1ビットから下の0ビットを見つける
 * - 3. 見つけた1ビットから上の0ビットを見つける
 * @return int 
 */
int main() {
    
    int N;
    cin >> N;
    vector<int> bit = displayData(N);
    int mask = pow(2,bit.size()) - 1;

    // 移動するところがなかったらもうそれでおしまい
    if ((N & mask) == mask) {
        cout << "no answer" << endl;
        return 0;
    }

    // 1. 最下位の1ビットを見つける
    int position = 0;
    for (int i = 0;i < bit.size(); ++i) {
        if (bit[i] == 1) {
            position = i;
            cout << "position = " << position << endl;
            break;
        }
    }

    // 2.見つけた1ビットから下の0ビットを見つける
    for (int i = position; i >= 0; --i) {
        if (bit[i] == 0) {
            int ans = (N + pow(2,i)) - pow(2, position);
            displayData(ans);
            cout << "prev "<< ans << endl;
            break;
        }
    }

    // 3. 見つけた1ビットから上の0ビットを見つける
    for (int i = position; i < bit.size(); ++i) {
        if (bit[i] == 0) {
            int ans = (N + pow(2,i)) - pow(2, position);
            displayData(ans);
            cout << "next "<< (N + pow(2,i)) - pow(2, position) << endl;
            break;
        }
    }

    return 0;
}