#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    string v;
    int red = 0;
    cin >> v;
    for (int i = 0; i < N; ++i) {
        if (v[i]=='R') red++;
    }
    
    int count = 0;
    for (int i = 0; i < red; ++i) {
        if (v[i] == 'W') count++;
    }
    cout  << count << endl;
    return 0;
}