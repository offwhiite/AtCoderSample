#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

/**
 * A - lowered Base salary
 * ボーナス比率がD:9.0%, CP:8.2% の時、昇給した量がいくらまでだったら月給が下がるかを求めなさい
 */
int main() {
    long long upSalary = 100000;
    long long baseSalary = 9000000;
    long long CP = baseSalary - (baseSalary * 86 / 1000); 
    long long D = baseSalary - (baseSalary * 9 / 100);
    cout << CP << endl;
    cout << D << endl;
    do {
        baseSalary += upSalary;
        D = baseSalary - (baseSalary * 9 / 100);
        cout << D << endl;
    } while(D < CP);

    cout  << baseSalary << endl;
    return 0;
}