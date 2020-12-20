#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    int A,B,C;
    cin >> A >> B >> C;
    int tmp = 0;
    tmp = A;
    A = B;
    B = tmp;
    tmp = A;
    A = C;
    C = tmp;
    
    cout  << A << " " << B << " " << C <<endl;
    return 0;
}