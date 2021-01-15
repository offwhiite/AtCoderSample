#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    long long b = K;
    int p = 1;
    while(N>=K){
        K*=b;
        p++;
    }
    
    cout << p << endl;
    return 0;
}