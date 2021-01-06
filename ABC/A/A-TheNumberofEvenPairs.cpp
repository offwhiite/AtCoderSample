#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

long long calcNumOfCombination(long long n, int r){
        long long num = 1;
        for(int i = 1; i <= r; i++){
            num = num * (n - i + 1) / i;
        }
        return num;
}

int main() {
    int N, M;
    cin >> N >> M;
    cout << calcNumOfCombination(N,2) + calcNumOfCombination(M,2) << endl;
    return 0;
}