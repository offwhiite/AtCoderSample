#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {

    const long long max = 1000000000000000000L; 
    
    int N;
    cin >> N;
    vector <long long> v(N+1,1);
    long long sum = 1;
    for (int i = 1; i < N + 1; ++i) { 
        cin >> v[i];
    }

    if (count(v.begin(),v.end(),0)) {
        cout << "0" << endl;
        return 0;
    }
    
    for (int i = 1; i < N + 1; ++i) { 
        string before = to_string(v[i-1]);
        string after = to_string(v[i]);
        if(before.size()-1 + after.size()-1 > 18) { 
            cout << "-1" << endl;
            return 0;
        }
        if (max / sum < v[i]) {
            cout << "-1" << endl;
            return 0;            
        }

        sum *= v[i]; 
    }

    cout  << sum << endl;
    return 0;
}