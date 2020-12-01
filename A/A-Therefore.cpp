#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
    string N;
    cin >> N;
    if(N[N.size()-1] == '0' || N[N.size()-1] == '1' || N[N.size()-1] == '6' || N[N.size()-1] == '8') {
        cout << "pon";
    } else if (N[N.size()-1] == '3') {
        cout << "bon";
    } else {
        cout << "hon";
    }
    
    cout  << endl;
    return 0;
}