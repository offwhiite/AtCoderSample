#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int K;
    cin >> K;
    string S;
    cin >> S;
    if (S.size() <= K) cout << S;
    else cout << S.substr(0,K) + "...";
    
    cout << endl;
    return 0;
}