#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
    int N; string S;
    cin >> N >> S; 
    int count = 0;
    char pre = ' ';
    for (int i = 0; i < N; ++i) {
        if (pre != S[i]){
            pre = S[i];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}