#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int A,B,C,N;
    cin >>A>>B>>C>>N;
    int ans = A;
    int count = N-A;
    if (count<0) ans = N;
    if (count>=0) count-=B;
    if (count>=0) ans -= count;
    
    cout  <<  ans << endl;
    return 0;
}